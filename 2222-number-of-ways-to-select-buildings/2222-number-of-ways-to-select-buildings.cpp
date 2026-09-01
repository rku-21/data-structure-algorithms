class Solution {
public:
    typedef long long ll;
    int n;
    ll dp[100001][3][4];
    ll solve(int i, int lastTaken, int left, auto&s){
        if(left==0) return 1LL;
        if(i>=n || left<0) return 0LL;
        if(dp[i][lastTaken+1][left]!=-1) return dp[i][lastTaken+1][left];
        ll ans=0;

        if(lastTaken==-1){
          
            ans+=solve(i+1,s[i]-'0', left-1, s);
        }
        else if(lastTaken != s[i]-'0'){
          
            ans+=solve(i+1, s[i]-'0', left-1, s);
        }
        ans+=solve(i+1,lastTaken, left,s);

        return dp[i][lastTaken+1][left]=ans;




    }
    long long numberOfWays(string s) {
        n=s.size();
        memset(dp,-1,sizeof(dp));
      
        return solve(0,-1,3,s);

        
    }
};