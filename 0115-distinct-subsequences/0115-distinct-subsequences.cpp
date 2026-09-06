class Solution {
public:
    int dp[1001][1001];
    int m;
    int n;
    int solve(int i, int j, auto&s,auto&t){
        if(j>=n) return 1;
        if(i>=m) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=0;
        if(s[i]==t[j]){
            ans+=solve(i+1,j+1,s,t);
        }
        ans+=solve(i+1,j,s,t);

        return dp[i][j]=ans;
        
    }
    int numDistinct(string s, string t) {
         m=s.size();
         n=t.size();
        memset(dp,-1,sizeof(dp));
        return solve(0,0,s,t);
        
    }
};