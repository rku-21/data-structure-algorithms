class Solution {
public:
    int m,n;
    int dp[2001][2001];
    bool solve(int i, int j, auto&s, auto&p,auto&shrink_stars){
        if(i>=m && j>=n) return true;
        if(j>=n) return false;
        if(i>=m){
            if(p[j]=='*' && shrink_stars[j]==n) return true;
            return false;
        }
        if(dp[i][j]!=-1) return dp[i][j];

        if(p[j]>='a' && p[j]<='z'){
            if( s[i] != p[j]) return dp[i][j]=false;
           return dp[i][j]=solve(i+1,j+1,s,p,shrink_stars);
        }
        else if(p[j]=='?'){
            return dp[i][j]=solve(i+1,j+1,s,p, shrink_stars);
        }
        else {
            bool skip=solve(i,shrink_stars[j], s, p, shrink_stars);
            bool match_curr=solve(i+1,j, s,p, shrink_stars);

            return dp[i][j]=(skip || match_curr);
                    
                    
        }



    }
    bool isMatch(string s, string p) {
        m=s.size();
        n=p.size();
        memset(dp,0,sizeof(dp));
        unordered_map<int,int>shrink_stars;
        int start=-1;
        int i=0;
        while(i<n){
            if(start==-1 && p[i]=='*') {
                start=i;
                while(i<n && p[i]=='*') i++;
                shrink_stars[start]=i;
                start=-1;
            }
            else i++;
        }
       

        // return solve(0,0,s,p,shrink_stars);

        // Tabulation dp 

        dp[m][n]=true;

        for(int i=0; i<m; i++) dp[i][n]=false;
        for(int j=0; j<n; j++){
            if(p[j]=='*' && shrink_stars[j]==n) dp[m][j]=true;
            else dp[m][j]=false;
        }

        for(int i=m-1; i>=0; i--){
            for(int j=n-1; j>=0; j--){
                if(p[j]>='a' && p[j]<='z'){
                    if(s[i]!=p[j]){
                        dp[i][j]=false;
                    }
                    else dp[i][j]=dp[i+1][j+1];

                }
                else if(p[j]=='?'){
                    dp[i][j]=dp[i+1][j+1];
                }
                else {
                    bool skip=dp[i][shrink_stars[j]];
                    bool match_curr=dp[i+1][j];

                    dp[i][j]= skip || match_curr;
                }
            }
        }

        return dp[0][0];





















        
    }
};