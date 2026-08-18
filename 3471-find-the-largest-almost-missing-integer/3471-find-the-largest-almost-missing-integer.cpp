class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        vector<int>freq(51,0);
        int n=nums.size();

        for(int i=0; i<k; i++){
            freq[nums[i]]=1;
        }
        int l=0;
        for(int i=k; i<n; i++){
            l++;
            for(int j=l; j<=i; j++) freq[nums[j]]++;
        
            
        }
        for(int i=50; i>=0; i--){
            if(freq[i]==1) return i;
        }
        return -1;


        
    }
};