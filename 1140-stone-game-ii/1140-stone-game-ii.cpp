class Solution {
public:
    int n;
    int dp[101][101];
    int solve(int i,int m,auto&pref){
        if(i>=n) return 0;
        if(dp[i][m]!=-1) return dp[i][m];
        int diff=INT_MIN;
        for(int x=0; x<2*m && x+i<n; x++){
           int curr_take=(pref[x+i]) - (i==0 ? 0 : pref[i-1]);
           int oppnent_take=(dp[x+i+1][max(m,x+1)]!=-1) ? dp[x+i+1][max(m,x+1)] : solve(x+i+1,max(m,x+1),pref);
           diff=max(diff,curr_take-oppnent_take);

        }

        return dp[i][m]=diff;






    }
    int stoneGameII(vector<int>& piles) {
        n=piles.size();
        if(n==1) return piles[0];
        vector<int>pref(n,0);
        pref[0]=piles[0];
        for(int i=1; i<n; i++){
             pref[i]=pref[i-1]+piles[i];
        }

        memset(dp,-1,sizeof(dp));

        int diff=solve(0,1,pref);

        int sum=0;
        for(int i=0; i<n; i++) sum+=piles[i];
        return (sum+diff)/2;


        
    }
};