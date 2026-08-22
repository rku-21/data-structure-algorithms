class Solution {
public:
int n;
    int dp[301][11];
    int solve(int i, auto&val, int d){
        if(i>=n && d==0) return 0;
        if(i>=n || d==0) return INT_MAX/2;

        if(dp[i][d]!=-1) return dp[i][d];

        int maxi=val[i];
        int ans=INT_MAX;

        for(int idx=i; idx<n; idx++){
            maxi=max(maxi, val[idx]);
            ans=min(ans,maxi+solve(idx+1,val, d-1));

        }

        return dp[i][d]=ans;




    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        n=jobDifficulty.size();
        if(d>n) return -1;
        memset(dp,-1,sizeof(dp));

        return solve(0,jobDifficulty, d);
        
    }
};