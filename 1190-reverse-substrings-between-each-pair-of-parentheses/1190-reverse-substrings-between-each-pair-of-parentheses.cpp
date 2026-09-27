class Solution {
public:
    string reverseParentheses(string s) {

        int n=s.size();

        stack<char>st;
        string ans="";

        for(auto x :s){
            if(x == ')'){
                string temp="";
                while(st.top() != '('){
                    temp.push_back(st.top());
                    st.pop();
                }
                st.pop();
              
                for(auto t : temp){
                    st.push(t);
                }
            }
            else {
                st.push(x);
            }
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
        
        
    }
};