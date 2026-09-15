class Solution {
public:
    int n;
   
    int dp[2001][2001];
    int solve(int i, int j, auto&s, int k,auto&isPalin){
        if(i>=n || j>=n) return 0;
        if(dp[i][j]!=-1) return dp[i][j];

        int ans=0;

        bool ok=isPalin[i][j];

        if(ok){
            ans=1+solve(j+1,j+k, s, k, isPalin);
        }

        else {
            ans=max(solve(i+1,j+1,s,k,isPalin), solve(i,j+1,s,k, isPalin));
        }

        return dp[i][j]=ans;





    }
    int maxPalindromes(string s, int k) {
        n=s.size();
        memset(dp, -1,sizeof(dp));
        vector<vector<bool>>isPalin(n, vector<bool>(n,false));

        for(int len=1; len<=n; len++){
            for(int i=0; i<=n-len; i++){
                int j=i+len-1;

                if(len == 1){
                    isPalin[i][j]=true;
                }
                else if(len==2){
                    isPalin[i][j]= s[i]==s[j];
                }
                else {
                    isPalin[i][j]= s[i]==s[j] && isPalin[i+1][j-1];
                }
            }
        }

        return solve(0, k-1,s, k,isPalin);
        
    }
};