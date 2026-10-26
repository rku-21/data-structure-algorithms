class Solution:
    n=None
    m=None
    def dfs(self , i:int , j:int , grid: List[List[int]])-> int:
        n=len(grid)
        m=len(grid[0])
        if i<0 or j<0 or i>=n or j>=m: 
             return 0
        if grid[i][j]==0: 
            return 0

        sum = grid[i][j]
        grid[i][j]=0
        dir = [1,0,-1,0,1]
        for d in range(4):
            x=dir[d]+i
            y=dir[d+1]+j
            sum+=self.dfs(x,y,grid)
        
        return sum
    
    def countIslands(self, grid: List[List[int]], k: int) -> int:
        n=len(grid)
        m=len(grid[0])
        count=0

        for i in range(n):
            for j in range(m):
                if grid[i][j]>0 :
                    sum=self.dfs(i,j,grid)
                    if sum % k==0 :
                        count+=1
        
        return count
        

        