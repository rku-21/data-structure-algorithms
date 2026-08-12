class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>freq;

        int max_len=0;
        int l=0;

        for(int r=0; r<n; r++){
            freq[nums[r]]++;
            while(freq[nums[r]]>k){
                freq[nums[l]]--;
                l++;
            }
            max_len=max(max_len,r-l+1);
        }
        return max_len;
        
    }
};