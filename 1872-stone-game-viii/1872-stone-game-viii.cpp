class Solution {
public:
    
    int stoneGameVIII(vector<int>& stones) {
       int n=stones.size();
        vector<int>dp(n,0);

        vector<int>pref(n+1,0);
        for(int i=1; i<=n; i++){
            pref[i]=pref[i-1]+stones[i-1];
        }

        // return solve(1,pref);
        dp[n-1]=pref[n];

        for(int i=n-2; i>=1; i--){
            int take=pref[i+1]-dp[i+1];
            int skip=dp[i+1];
            dp[i]=max(take, skip);
        }

        return dp[1];


        
    }
};