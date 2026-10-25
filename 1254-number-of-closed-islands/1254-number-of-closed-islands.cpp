class Solution {
public:
    int n,m;
    bool possible(int i, int j ,auto&grid){
        grid[i][j]=1;
        int dir[5]={1,0,-1,0,1};
        bool ans=true;

        for(int d=0; d<4; d++){
            int x=i+dir[d];
            int y=j+dir[d+1];
            if(x<0 || y<0 || x>=n || y>=m) ans=false;
            if( x>=0 && y>=0 & x<n && y<m && grid[x][y]==0){
                 bool check=possible(x,y,grid);
                 if(check==false) ans=false;

            }

        }
        return ans;

    }
    int closedIsland(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        int ans=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==0){
                    if(possible(i,j,grid)) ans++;
                }
            }
        }
        return ans;




        
    }
};