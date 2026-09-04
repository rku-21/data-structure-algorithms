class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>mini(n);
        int min_till=INT_MAX;
        for(int i=n-1; i>=0; i--){
            min_till=min(min_till, nums[i]);
            mini[i]=min_till;
        }

        int maxi=INT_MIN;
        for(int i=0; i<n; i++){
            maxi=max(nums[i], maxi);
          
          int score=maxi-mini[i];
        
          if(score <=k) return i;
        }
        return -1;


        
    }
};