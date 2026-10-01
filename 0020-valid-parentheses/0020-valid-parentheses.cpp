class Solution {
public:
    bool isValid(string s) { 
        int n=s.size();
        stack<char>st;
        for(int i=0; i<n; i++){
            char ch=s[i];
            if(ch=='(' || ch=='{' || ch=='['){
                st.push(ch);
                continue;
            
            }
            if(!st.empty()){
            auto top=st.top();
            if((top=='(' && ch==')') || (top=='{' && ch=='}') || (top=='[' && ch==']')) {
                st.pop();
                continue;
                
             }
            }
            return false;
            




        }
        if(st.empty()) return true;
        return false;

        
    }
};