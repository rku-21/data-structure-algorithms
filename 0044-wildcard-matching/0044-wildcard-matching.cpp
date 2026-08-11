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
        memset(dp,-1,sizeof(dp));
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
       

        return solve(0,0,s,p,shrink_stars);
        
    }
};