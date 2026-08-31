/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
   bool isCritical(ListNode* curr, ListNode* prev , ListNode* next){
        
         return  ((curr->val > prev->val) && (curr->val > next->val)) || ((curr->val < prev->val) && (curr->val < next->val));
   }
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(!head->next->next) return {-1,-1};
        ListNode* first=nullptr;
        ListNode* recentCritical=nullptr;

        int maxi=INT_MIN;
        int mini=INT_MAX;
        int firstPos=-1;
        int recentPos=-1;

        ListNode* curr=head->next;
        ListNode* prev=head;
        ListNode* next=curr->next;
        int dist=0;

        while(next!=nullptr){
            if(isCritical(curr, prev, next)){
                

                if(first==nullptr){
                    first=curr;
                    firstPos=dist;
                }
                else {
                    maxi=max(maxi, dist - firstPos);
                    mini=min(mini, dist - recentPos);
                }
                 recentPos=dist;
                 recentCritical=curr;



            }
            prev=curr;
            curr=next;
            next=next->next;
            dist++;
            

        }
        if(maxi==INT_MIN)  return {-1,-1};
        return {mini, maxi};

        



        
    }
};