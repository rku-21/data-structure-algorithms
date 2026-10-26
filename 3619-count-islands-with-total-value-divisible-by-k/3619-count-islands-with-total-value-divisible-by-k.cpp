class Solution {
public:
   int n,m;
   typedef long long ll;
    ll isLandSum(int i, int j, auto&grid,auto&vis){
          vis[i][j]=true;

         ll sum=grid[i][j];
          int dir[5]={1,0,-1,0,1};
          for(int d=0; d<4; d++){
             int x=dir[d]+i;
             int y=dir[d+1]+j;
             if(x>=0 && y>=0 && x<n && y<m && !vis[x][y] && grid[x][y]!=0){
                 sum+=isLandSum(x,y, grid,vis);
             }
          }
          return sum;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
         n=grid.size();
        m=grid[0].size();

        int ans=0;
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j] && grid[i][j]!=0){
                    ll sum=isLandSum(i,j,grid,vis);
                 
                    if(sum % k==0) ans++;
                }
            }
        }
        return ans;


        
    }
};