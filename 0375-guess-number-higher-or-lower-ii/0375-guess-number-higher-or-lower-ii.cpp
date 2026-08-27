class Solution {
public:
    int n;
    int dp[201][201];
    int solve(int l, int r){
        if(l>=r) return 0;
        if(dp[l][r]!=-1) return dp[l][r];
        int ans=INT_MAX;
        for(int i=l; i<=r; i++){
            int cost=i+max(solve(l , i-1), solve(i+1,r));
            ans=min(ans,cost);
            
           
            
        }

        return dp[l][r]=ans;





    }
    int getMoneyAmount(int n) {
            n=n;
            memset(dp,-1,sizeof(dp));

            return solve(1,n);
       
    }
};