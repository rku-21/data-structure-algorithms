class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string>digLogs;
        vector<string>letterLogs;
        int n=logs.size();

        for(auto s: logs){
            if(s[s.size()-1]>='0' && s[s.size()-1]<='9'){
                digLogs.push_back(s);
            }
            else letterLogs.push_back(s);
        }

        sort(letterLogs.begin() , letterLogs.end(), [](const auto& a , const auto&b){
            string a1=a.substr(a.find(' ')+1);
            string b1=b.substr(b.find(' ')+1);

            if(a1==b1){
               return  a.substr(0,a.find(' ')) < b.substr(0,b.find(' '));
            }

            return a1 < b1;



        });

        for(auto d:  digLogs){
            letterLogs.push_back(d);
        }

        return letterLogs;





       

        
    }
};