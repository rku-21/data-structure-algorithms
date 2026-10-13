class Solution {
public:
    typedef long long ll;
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();

        for(auto &num : nums) num=abs(num);
        sort(nums.begin(), nums.end());
       
        ll ans=0;
        int bigCnt=(n+1)/2;
        int j=n-1;
        while(bigCnt--){
           ans += nums[j] * nums[j];
           j--;
        }
        while(j>=0){
            ans -= nums[j] * nums[j];
            j--;
        }
        return ans;

        
    }
};