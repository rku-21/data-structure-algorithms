class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        vector<vector<bitset<1024>>>dp(m,vector<bitset<1024>>(n,bitset<1024>()));
        dp[m-1][n-1].set(grid[m-1][n-1]);
        int dir[3]={1,0,1};
        for(int i=m-1; i>=0; i--){
            for(int j=n-1; j>=0; j--){
                if(i==m-1 && j==n-1) continue;
                for(int d=0; d<2; d++){
                    int x=i+dir[d];
                    int y=j+dir[d+1];
                    if(x>=m || y>=n) continue;
                    for(int k=0; k<1024; k++){
                        if(dp[x][y].test(k)) {
                             dp[i][j].set(k^grid[i][j]);
                        
                        }
                       
                    }
                }



            }
        }
        int ans=INT_MAX;
        for(int i=0; i<1024; i++){
          if(dp[0][0].test(i)) {
                ans=min(ans,i);
          }
        }
        return ans;


        
    }
};