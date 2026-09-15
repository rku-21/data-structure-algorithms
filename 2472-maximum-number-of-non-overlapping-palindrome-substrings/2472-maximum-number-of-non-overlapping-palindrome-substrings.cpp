class Solution {
public:
    int n;
    bool ispalin(int i, int j, auto&s){
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        } 
        return true;
    }
    int dp[2001][2001];
    int solve(int i, int j, auto&s, int k){
        if(i>=n || j>=n) return 0;
        if(dp[i][j]!=-1) return dp[i][j];

        int ans=0;

        bool ok=ispalin(i, j,s);

        if(ok){
            ans=1+solve(j+1,j+k, s, k);
        }

        else {
            ans=max(solve(i+1,j+1,s,k), solve(i,j+1,s,k));
        }

        return dp[i][j]=ans;





    }
    int maxPalindromes(string s, int k) {
        n=s.size();
        memset(dp, -1,sizeof(dp));

        return solve(0, k-1,s, k);
        
    }
};