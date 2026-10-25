/**
 * @param {number[][]} grid
 * @return {number}
 */
 var n,m;
 function markOne(i,j,grid){
    grid[i][j]=1;

    let dir=[1,0,-1,0,1];
    for(let d=0; d<4; d++){
        let x=i+dir[d];
        let y=j+dir[d+1];

        if(x>=0 && y>=0 && x<n && y<m && grid[x][y]==0){
            markOne(x,y,grid);

        }


    }
}
var closedIsland = function(grid) {
    n=grid.length;
    m=grid[0].length;
    
    for(let i=0; i<n; i++){
      if(grid[i][0]==0){
         markOne(i,0,grid);
      }
      if(grid[i][m-1]==0){
        markOne(i,m-1,grid);
      }
        
    }

    for(let j=0; j<m; j++){
        if(grid[0][j]==0){
            markOne(0,j,grid);
        }
        if(grid[n-1][j]==0){
            markOne(n-1,j,grid);
        }
    }
     let ans=0;
    for(let i=1; i<n-1; i++){
        for(let j=1; j<m-1; j++){
            if(grid[i][j]==0) {
                markOne(i,j,grid);
                ans++;
            }
        }
    }
    return ans;





    
};