class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();

        int ans=0;
        int currZero=0;

        int l=0;
        for(int r=0; r<n; r++){
            if(nums[r]==0) currZero++;

            while(currZero > k){
                if(nums[l]==0) {
                    currZero--;
                }
                l++;
            }
            ans=max(ans, r-l+1);
        }
        return ans;
        
    }
};