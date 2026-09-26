class Solution {
public:
     int n;
    string giveKey(int idx, auto&s){
        string temp="";
      
        while(idx<n && s[idx]!=')'){
            // cout<<s[idx]<<endl;
            temp.push_back(s[idx]);
            idx++;
        }
        
        return temp;
    }
       string evaluate(string s, vector<vector<string>>& knowledge) {
        n=s.size();

        string ans="";
        unordered_map<string,string>mp;
        for(auto k : knowledge){
            mp[k[0]]=k[1];
        }
        int i=0; 
        while(i<n){
            if(s[i]=='('){
                string temp=giveKey(i+1, s);
                cout<<temp<<endl;
                if(mp.count(temp)){
                    ans+=mp[temp];
                }
                else ans.push_back('?');

                i+=temp.size()+2;
            }
            else {
                ans.push_back(s[i]);
                i++;
            }
           
        }

        return ans;

    
        
    }
};