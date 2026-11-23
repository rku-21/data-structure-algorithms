class ProductOfNumbers {
public:
    vector<int>prefP;
    ProductOfNumbers() {
         prefP.push_back(1);
      
      

        
    }
    
    void add(int num) {
        if(num==0){
            prefP.clear();
             prefP.push_back(1);
             return;
        }
       
        if(prefP.size()==0) prefP.push_back(num);
       
        else {
            int size=prefP.size();
            prefP.push_back(prefP[size-1]*num);
        }
       
        
    }
    
    int getProduct(int k) {

        int size=prefP.size();
        if(k>=size) return 0;
        int idx=size-k-1;
        return prefP[size-1]/prefP[idx];
        
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */