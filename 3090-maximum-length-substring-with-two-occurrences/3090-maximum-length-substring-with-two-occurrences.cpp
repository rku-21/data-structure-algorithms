class Solution {
public:
   bool valid(auto&freq){
       for(int i=0; i<26; i++){
           if(freq[i]>2) return false;
       }
       return true;
   }
    int maximumLengthSubstring(string s) {
        int n=s.size();
        vector<int>freq(26,0);

        int l=0;
        int maxlen=1;
        for(int r=0; r<n; r++){
            int idx=s[r]-'a';
            freq[idx]++;

            while(!valid(freq)){
                freq[s[l]-'a']--;
               
                l++;
            }
            maxlen=max(maxlen, r-l+1);
        }

        return maxlen;


        
    }
};