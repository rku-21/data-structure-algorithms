class Solution {
public:
    int longestValidParentheses(string s) {
        int n=s.size();
        if(n==0) return 0;
        

        int ans,open,close;
        ans=open=close=0;
        int i=0;
        while(i<n && s[i]==')') i++;

        for(i; i<n; i++){

            if(s[i]=='(') open++;
            else close++;

            if(open == close ) ans=max(ans, open + close);

            if(close > open) {
                open =close =0;
            }
        }

        open=close=0;
        i=n-1;
        while(i<n && s[i]=='(') i++;
        
        for(i; i>=0; i--){
            if(s[i]==')') close++;
            else open++;

            if(open == close ) ans=max(ans, open + close);
            
            if(open > close ){
                open =close =0;
            }
        }

        return ans;
        
    }
};