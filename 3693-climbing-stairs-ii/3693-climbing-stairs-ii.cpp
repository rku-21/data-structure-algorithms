class Solution {
public:
    int maxi=1e7;
    int climbStairs(int n, vector<int>& costs) {
       

        vector<int>dp(n+1,0);
        dp[n]=0;
        for(int i=n-1; i>=0; i--){
            int a1=costs[i]+1+dp[i+1];
            int a2=maxi;
            int a3=maxi;

            if(i+1<n){
                a2=costs[i+1]+4+dp[i+2];
            }
            if(i+2<n){
                a3=costs[i+2]+9+dp[i+3];
            }

            dp[i]=min({a1,a2,a3});
        }

        return dp[0];
        
    }
   
};