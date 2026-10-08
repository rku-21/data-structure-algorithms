class Solution {
public:
    string removeOuterParentheses(string s) {
        int n=s.size();

        string ans="";
        string temp="";
        int diff=0;
        for(int i=0; i<n; i++){
            if(diff == 0 && s[i]=='(') {
                diff++;
                continue;
            }
            int val = s[i]=='(' ? 1 : -1;
            diff+=val;
            
            if(diff==0 && s[i]==')') {
                ans+=temp;
                diff =0;
                temp="";
                continue;
            }
            temp.push_back(s[i]);
           

        }

        return ans;






        
    }
};