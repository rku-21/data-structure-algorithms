class Solution {
public:
    int m,n;
    int mod=1e9+7;
    int dp[501][501][2];
    int solve(int i, int j, auto&grid,bool isUp){
        if(i>=m || j>=n) return 0;
        if(i==m-1 && j==n-1) return 1;
        if(dp[i][j][isUp] !=-1) return dp[i][j][isUp];

        bool isMirror=grid[i][j];
        int ans=0;
        if(isMirror){
            if(isUp) {
                ans= (ans + solve(i,j+1,grid,false))%mod;
            }
            else ans = (ans+solve(i+1,j,grid,true))%mod;

        }
        else {
            ans=(ans+solve(i+1,j,grid,true))%mod;
            ans=(ans+solve(i,j+1,grid, false))%mod;
        }
        return dp[i][j][isUp]=ans%mod;

    }
    int uniquePaths(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        memset(dp,-1,sizeof(dp));
        int ans=solve(0,0,grid,false);
        return ans %mod;
        
    }
};