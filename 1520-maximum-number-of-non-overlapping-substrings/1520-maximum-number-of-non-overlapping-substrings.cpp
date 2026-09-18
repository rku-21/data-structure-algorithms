class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n=s.size();
        vector<int>start(26,-1);
        vector<int>end(26,-1);

        for(int i=0; i<n; i++){
            if(start[s[i]-'a']==-1) start[s[i]-'a']=i;
            end[s[i]-'a']=i;
        }
        
       
         vector<int>isValid(26,true);
        for(int i=0; i<26; i++){
            if(start[i]!=-1){
                for(int idx=start[i]; idx<=end[i]; idx++){
                    end[i]=max(end[i], end[s[idx]-'a']);

                    if(start[i] > start[s[idx]-'a']){
                       
                        isValid[i]=false;
                        break;
                    }
                }
            }
        }

   

        vector<string>ans;
        int lastTaken=n;
      
        for(int i=n-1; i>=0; i--){
            int charIdx=s[i]-'a';
            if(!isValid[charIdx]) continue;


            if(start[charIdx]==i && end[charIdx]<lastTaken){
                ans.push_back(s.substr(i, end[charIdx]-start[charIdx]+1));
                lastTaken=i;
            }

        }

        return ans;














        
    }
};