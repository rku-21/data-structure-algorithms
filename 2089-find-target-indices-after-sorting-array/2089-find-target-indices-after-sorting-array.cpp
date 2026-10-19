class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int n=nums.size();

        vector<int>ans;
        sort(nums.begin(),nums.end());
        int i=0;
        while(i<n && nums[i]!=target) i++;
        while(i<n && nums[i]==target) {
            ans.push_back(i);
            i++;
        }
        return ans;


        
    }
};