class LRUCache {
public:
    struct dll {
        dll* prev;
        dll* next;
        int val;
        int key;

        dll(int val, int key) :val(val), key(key) , next(nullptr), prev(nullptr) {};

    };
    
    int capacity;
    unordered_map<int,dll*>mp;

    dll* head=nullptr;
    dll* rear =nullptr;

    LRUCache(int capacity) : capacity(capacity) {};

    void moveToFront(dll* recent ,dll* back, dll* ahead){
        if(head == recent) return;

        if(recent == rear){
            rear = back;
        }

        if(back) back->next = ahead;
        if(ahead) ahead->prev = back;
        recent -> prev = nullptr;
        recent->next = head;
        if(head) head->prev=recent;
        head = recent;




    }
        
    
    
    int get(int key) {
        if(!mp.count(key)) return -1;

        // move to front 
        dll* recent = mp[key];
        dll* back = recent->prev;
        dll* ahead = recent->next;
        moveToFront(recent, back, ahead);

        

        return mp[key]->val;
    }
    
    void put(int key, int value) {

        if(head==nullptr){
            dll* node =new dll(value, key);
            mp[key]=node;
            head=node;
            rear=node;
           
            return;
        }

        else if (mp.count(key)) {
             // alredy existing so update 

            dll* recent = mp[key];
            dll* back = recent->prev;
            dll* ahead = recent->next;

            recent->val=value;
            mp[key]=recent;

            moveToFront(recent, back, ahead);
        }

        else {
            // not existing so insert 

            if(mp.size()==capacity){
                dll* temp=rear;
                if(head == rear){
                    head= nullptr;
                    rear =nullptr;
                }
                else {
                   rear = rear->prev;
                   rear->next=nullptr;
                }
                mp.erase(temp->key);
                delete temp;



            }
            dll* node =new dll(value, key);
            if(head == nullptr){
                head=node;
                rear=node;
            }
            else {
                node->next=head;
                head->prev=node;
                head = node;
            }
            mp[key]=head;
           
      }
      }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */