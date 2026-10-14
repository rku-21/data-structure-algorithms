class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>cnt(k+1,0);

        int sum=0;
        int ans=0;
        cnt[0]=1;
        for(int r=0; r<n; r++){
            sum+=nums[r];
            int rem=((sum%k)+k)%k;
            ans+=cnt[rem];
          
            cnt[rem]++;

        }
        return ans;
        
    }
};