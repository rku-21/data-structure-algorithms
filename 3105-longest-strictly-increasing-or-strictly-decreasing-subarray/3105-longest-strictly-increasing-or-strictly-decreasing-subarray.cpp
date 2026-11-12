class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n=nums.size();

       
        int ans=1;
        int l=0;
        for(int i=0; i<n-1;){
            while(i<n-1 && nums[i]==nums[i+1]) i++;
            l=i;
            if(i<n-1 && nums[i]>nums[i+1]) {
                while(i<n-1 && (nums[i]>nums[i+1])) {
                    i++;
                }
                ans=max(ans, i-l+1);

            }
            else {
                while(i<n-1 && (nums[i]<nums[i+1])) {
                    i++;
                }
                ans=max(ans, i-l+1);
            }
           
           
           





        }
        return ans;
        
    }
};