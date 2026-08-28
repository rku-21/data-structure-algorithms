class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m=dungeon.size();
        int n=dungeon[0].size();

        vector<vector<int>>dp(m,vector<int>(n,1));

        if(dungeon[m-1][n-1]<0) dp[m-1][n-1]+=abs(dungeon[m-1][n-1]);

        for(int j=n-2; j>=0; j--){
            int required=dp[m-1][j+1];
            dp[m-1][j]=max(required-dungeon[m-1][j], 1);
        }

        for(int i=m-2; i>=0; i--){
            int required=dp[i+1][n-1];
            dp[i][n-1]=max(required-dungeon[i][n-1], 1);
        }

        for(int i=m-2; i>=0; i--){
            for(int j=n-2; j>=0; j--){
                int val=dungeon[i][j];
                dp[i][j]=min(dp[i+1][j]-val , dp[i][j+1]-val);

                if(dp[i][j]<0) dp[i][j]=1;


            }
        }

        return dp[0][0];




        
    }
};