class Solution {
public:
int n;
    int dp[101][101];
    int palin(auto& t){
        int i=0;
        int j=t.size()-1;
        int cnt=0;
        while(i<j){
            if(t[i]!=t[j]) cnt++;
            i++;
            j--;
        }
        return cnt;
    }
    int solve(int i, auto&s, int k){
        if(k==0 && i>=n) return 0;
        if(i>=n || k<0) return INT_MAX/2;
        if(dp[i][k]!=-1) return dp[i][k];
        int ans=INT_MAX/2;
        for(int idx=i; idx<n; idx++){
            string temp=s.substr(i, idx-i+1);
            int x=palin(temp);
            ans=min(ans, x+solve(idx+1, s, k-1));
        }

        return dp[i][k]=ans;

    }
    int palindromePartition(string s, int k) {
     n=s.size();
     memset(dp,-1,sizeof(dp));

        return solve(0,s,k);
        
    }
};