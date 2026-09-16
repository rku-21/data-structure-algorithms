class Solution {
public:
    int mod=1e9+7;
    int dp[1001][1001][2];
    int solve(int currIdx, int leftK, int started, int n){
        if (leftK==0) return 1;
        if(currIdx>=n) return 0;

        if(dp[currIdx][leftK][started]!=-1) return dp[currIdx][leftK][started];

        int ans=0;

        if(started ==1 ){
            ans=(ans+solve(currIdx+1, leftK, started, n)) %mod;
            ans=(ans+solve(currIdx, leftK-1,0,n))%mod;
        }
        else {
            // skiping the currIdx , fully 
            ans=(ans+solve(currIdx+1, leftK,0, n)) %mod;
            // starting a segement for currIdx 
            ans=(ans+solve(currIdx+1, leftK,1,n)) %mod;

        }
        return dp[currIdx][leftK][started] = ans %mod;
    }
    int numberOfSets(int n, int k) {
           memset(dp, -1, sizeof(dp));
        return solve(0, k, 0, n);
        
    }
};