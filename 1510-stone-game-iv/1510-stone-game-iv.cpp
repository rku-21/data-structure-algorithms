class Solution {
public:
    int dp[100001][2];
    int solve(int stonesLeft, bool turn){
        if(stonesLeft==0){
            return false;
        }
        if(dp[stonesLeft][turn]!=-1) return dp[stonesLeft][turn];
         bool ans=false;
        for(int i=1; i*i<=stonesLeft; i++){
            if(!solve(stonesLeft-(i*i),!turn)){
                ans=true;
                break;
            }
           
        }
        return dp[stonesLeft][turn]=ans;


    }
    bool winnerSquareGame(int n) {
        vector<bool>perfect_square(n+1,false);
        memset(dp,-1,sizeof(dp));

        
       
        return solve(n,true);


        
    }
};