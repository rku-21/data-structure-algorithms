class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int s=0;
        int e=0;

        int ans=INT_MAX;
        int n=nums.size();
        int sum=0;

        while(e<n){
            sum+=nums[e];
            while(sum >=target){
                 ans=min(ans, e-s+1);
                sum-=nums[s];
                s+=1;
            }
            e++;
        }

        return ans==INT_MAX?0:ans;
        
    }
};