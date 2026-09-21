class Solution {
public:
    typedef long long ll;
    vector<long long> resultArray(vector<int>& nums, int k) {
        int n=nums.size();
        vector<vector<ll>>dp(n, vector<ll>(k,0));

        for(int i=0; i<n; i++){
            int new_r=nums[i]%k;
            dp[i][new_r]+=1;

            for(ll r=0; r<k; r++){
                if( i>0 && dp[i-1][r] >0){
                    ll new_r= (r * 1LL*nums[i]) %k;
                    dp[i][new_r]+=dp[i-1][r];
                }
            }
        }
        vector<ll>ans(k);
        for(int i=0; i<n; i++){
            for(int r=0; r<k; r++){
                ans[r]+=dp[i][r];
            }
        }
        return ans;

        
    }
};