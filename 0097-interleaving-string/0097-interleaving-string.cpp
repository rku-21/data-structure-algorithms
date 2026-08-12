class Solution {
public:
    int n,m,p;
    int t[101][101][201];
    bool solve(int i, int j, int k, auto&s1, auto&s2, auto&s3){
        if(i>=n && j>=m && k>=p) return true;
        if(k>=p) return false;
        if(t[i][j][k]!=-1) return t[i][j][k];
        bool ans=false;

        if(s1[i]==s3[k]){
            ans=solve(i+1,j,k+1,s1,s2,s3);
        }
        if(ans) return t[i][j][k]=ans;
        if(s2[j]==s3[k]){
            ans=solve(i,j+1,k+1,s1,s2,s3);
        }
        return t[i][j][k]=ans;
    }
    bool isInterleave(string s1, string s2, string s3) {
        n=s1.size();
        m=s2.size();
        // memset(t,-1,sizeof(t));
         p=s3.size();
        // return solve(0,0,0, s1,s2,s3);

        // we actually need i and j as at any point k=i+j 

        vector<vector<int>>dp(101,vector<int>(101,false));

        for(int i=0; i<=n; i++){
            for(int j=0; j<=m; j++){
                if(i+j==p) dp[i][j]=false;
            }
        }

        if(n+m==p){
            dp[n][m]=true;
        }

        for(int i=n; i>=0; i--){
            for(int j=m; j>=0; j--){
                if(i==n && j==m) continue;
                bool ans=false;
                if(i<n && i+j<p  && s1[i]==s3[i+j]){
                    ans= ans || dp[i+1][j];
                }

                if(i+j<p && j<m && s2[j]==s3[i+j]){
                    ans= ans || dp[i][j+1];
                }

                dp[i][j]=ans;
            }
        }

        return dp[0][0];

       
        


        
        

       

        return dp[0][0];






        
    }
};