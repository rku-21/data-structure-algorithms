class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n=nums.size();
        int xor_all=0;
         bool all_zero=true;
        for(int i=0; i<n; i++){
            xor_all^=nums[i];
            if(nums[i]!=0) all_zero=false;

        }
        if(all_zero) return 0;

        if(xor_all==0) return  n-1;
        else return n;

        
    }
};