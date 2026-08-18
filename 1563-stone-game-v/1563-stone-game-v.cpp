class Solution {
public:
    int n;
    int dp[501][501];
    int solve(int l, int r, auto&pref){
        if(l==r){
            return 0;
        }
        int ans=INT_MIN;
        if(dp[l][r]!=-1) {
            return dp[l][r];
        }

        for(int i=l; i<r; i++){
            int sum1=pref[i+1]-pref[l];
            int sum2=pref[r+1]-pref[i+1];

            if(sum1 < sum2){
              
                ans=max(ans, sum1+solve(l,i,pref));

            }
            else if(sum2 < sum1){
               
                ans=max(ans,sum2+solve(i+1,r,pref));
            }
            else {
                ans=max(ans,sum1+max(solve(l,i,pref),solve(i+1,r,pref)));
            }
        }

        return dp[l][r]=ans;

    }
    int stoneGameV(vector<int>& stoneValue) {
         n=stoneValue.size();
         vector<int>pref(n+1,0);
         memset(dp,-1,sizeof(dp));
         for(int i=1; i<=n; i++){
            pref[i]=pref[i-1]+stoneValue[i-1];
         }

        return solve(0, n-1, pref);
        
    }
};