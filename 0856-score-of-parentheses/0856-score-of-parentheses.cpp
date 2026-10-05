class Solution {
public:
    int scoreOfParentheses(string s) {

        int n=s.size();

        stack<string>st;

        for(int i=0; i<n; i++){
            if(s[i]=='('){
                st.push(string(1,'('));
            }
            else if(st.top() == "(") {
                 st.pop();
                st.push(string(1,'1'));
               
            }
            else {
                int temp=0;
                while(!st.empty() && st.top() != "("){
                    temp+=stoi(st.top());
                    st.pop();

                }
                if(!st.empty()) {
                    temp*=2;
                    st.pop();
                    st.push(to_string(temp));

                }
                
            }
        }
         int temp=0;
            while(!st.empty() && st.top() != "("){
                    temp+=stoi(st.top());
                    st.pop();

            }
            return temp;


      




        
    }
};