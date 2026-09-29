 int dp[101][101][5005];
class Solution {
public:
    int m,n;
  
    bool solve(int i, int j, int diff, auto&grid){
        if(2*diff > m*n) return false;
        if(i==m-1 && j==n-1){
            if(diff == 0) return true;
            return false;
        }
        if(dp[i][j][diff]!=-1) return dp[i][j][diff];
        bool ans=false;
        if(i+1<m){
            if(grid[i+1][j]==')' && diff>0){
                ans = ans | solve(i+1, j, diff-1, grid);

            }
            else if(grid[i+1][j]=='('){
                ans =ans | solve(i+1, j, diff+1, grid);
            }
            
        }

        if(j+1 < n){
            if(grid[i][j+1]==')' && diff>0){
                ans=ans | solve(i, j+1, diff-1, grid);
            }
            else if(grid[i][j+1]=='('){
                ans= ans | solve(i,j+1, diff+1, grid);
            }
        }
        return dp[i][j][diff]=ans;
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        m=grid.size();
        n=grid[0].size();
        memset(dp, -1, sizeof(dp));

        if(grid[0][0]==')') return false;
        return solve(0,0,1,grid);
        
    }
};