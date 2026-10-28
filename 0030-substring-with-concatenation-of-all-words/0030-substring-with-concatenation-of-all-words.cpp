class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int n=s.size();
        unordered_map<string,int>mp,compareMp;
        for(auto word:words){
            mp[word]++;
        }
        int wordlen=words[0].size();
        int totalLen=words.size();
        vector<int>ans;

        for(int o=0; o<wordlen; o++){
            int l=o;
            int wordCnt=0;
            for(int r=l; r<=n-wordlen; r+=wordlen){
                string temp=s.substr(r,wordlen);
                compareMp[temp]++;
                wordCnt++;

               
                while(compareMp[temp]>mp[temp]){
                compareMp[s.substr(l,wordlen)]--;
                wordCnt--;
               l+=wordlen;
                  
                } 
                if(wordCnt==totalLen) ans.push_back(l);

            }
            compareMp.clear();
            
        }

        return ans;





        
    }
};