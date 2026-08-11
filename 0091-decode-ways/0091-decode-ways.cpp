class Solution {
public:
   int n;
   int dp[101];
   int solve(int i, auto& s){
       if(i>=n) return 1;
       if(dp[i]!=-1) return dp[i];
       int ans=0;
       int digit1=s[i]-'0';
       if(digit1){
          ans+=solve(i+1,s);
          if(i+1<n){
            int digit2=s[i+1]-'0';
            int num=digit1*10+digit2;
            if(num<=26){
                ans+=solve(i+2,s);
            }
          }
       }

       return dp[i]=ans;
       



   }
    int numDecodings(string s) {
         n=s.size();
        if(s[0]=='0') return 0;
        memset(dp,-1,sizeof(dp));
        return solve(0,s);

        
    }
};