class Solution {
public:
    string mostCommonWord(string s, vector<string>& banned) {
        unordered_map<string,int>freq;

        int i=0;
        int n=s.size();

        while(i<n){
            string temp="";
            while(i<n && ((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z'))){
                temp.push_back(s[i]);
                i++;

            }
            transform(temp.begin(), temp.end(), temp.begin(), [](char ch){
                return tolower(ch);
            });
            freq[temp]++;
              while( i<n && !((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z'))) i++;
            
         }

         for(auto b :banned){
            freq[b]=0;
         }

         int max_freq=0;
         string ans="";
         for(auto f:freq){
            if(f.second>max_freq){
                ans=f.first;
                max_freq=f.second;
            }
         }

         return ans;


         






       


        
    }
};