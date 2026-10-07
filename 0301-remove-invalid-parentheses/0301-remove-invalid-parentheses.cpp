class Solution {
public:
     int n;
    void solve(int idx, int diff, int delete_count ,auto&temp, auto&store,auto&s){

        if(idx>=n) {
            if(diff==0) {
                store[delete_count].insert(temp);
                
            }
            return;
        }

        if(s[idx]>='a' && s[idx]<='z') {
             temp.push_back(s[idx]);
             solve(idx+1, diff, delete_count , temp, store, s);
             temp.pop_back();
        }

        else if(s[idx]=='(') {
             temp.push_back('(');
             solve(idx+1, diff+1, delete_count, temp, store, s);
             temp.pop_back();
             
             solve(idx+1, diff, delete_count+1, temp, store , s);

            
        }

       else if(s[idx]==')') {
            
            if(diff>0){
                temp.push_back(')');
                solve(idx+1, diff-1, delete_count, temp, store, s);
                temp.pop_back();
            }
            solve(idx+1, diff, delete_count+1, temp, store , s);
          
            

        }
         



    }
    vector<string> removeInvalidParentheses(string s) {
         n=s.size();
        vector<set<string>>store(26);

        string temp="";

        solve(0,0,0, temp,store,s);
        vector<string>ans;

        for(auto st : store){
            if(st.empty()) continue;
            for(auto s :st){
                ans.push_back(s);
            }
            break;
        }
        return ans;


        
    }
};