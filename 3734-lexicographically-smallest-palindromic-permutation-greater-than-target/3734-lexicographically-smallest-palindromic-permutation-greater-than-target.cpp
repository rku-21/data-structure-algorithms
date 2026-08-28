class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {

        int n=s.size();
        vector<int>freq(26,0);
        string ans="";

        for(auto ch : s) freq[ch-'a']++;

        int oddFreqCnt=0;
        char oddChar='{';
        for(int i=0; i<26; i++){
            if(freq[i]&1) {
                oddFreqCnt++;
                oddChar=i+'a';
                freq[i]--;
            }
        }
        

        if(oddFreqCnt > 1) return "";
        for(int i=0; i<26; i++){
            freq[i]=freq[i]/2;
        }

        int len=n/2;

        for(int i=0; i<len; i++){
            int idx=target[i]-'a';

            if(freq[idx]) {
                ans.push_back(idx+'a');
                freq[idx]--;
                continue;
            }

            else {
                 
                  for(int  x=idx+1; x<26; x++){
                     if(freq[x]){
                        ans.push_back(x+'a');
                        freq[x]--;

                        for(int i=0; i<26; i++){
                            if(freq[i]) {
                                ans.append(freq[i], i+'a');
                                if(ans.size()==len) {
                                       string rev=ans;
                                     if(oddChar != '{') ans.push_back(oddChar);
                                   
                                     reverse(rev.begin(), rev.end());
                                     return ans+rev;
                                }
                            }
                        }

                        
                        


                     }


                  }
            }

            break; // need brackTrack 


        }
        if(ans.size()==len) {
               string rev=ans;
        reverse(rev.begin(), rev.end());
        if(oddChar!='{' && ans+oddChar+rev > target){
            return ans+oddChar+rev;
             
        }
        else if(oddChar=='{' && ans+rev > target) return ans+rev;
        }


        

        for(int i=ans.size()-1; i>=0; i--){
            int idx=ans[i]-'a';

            freq[idx]++;
            ans.pop_back();

            for(int  x=idx+1; x<26; x++){
                     if(freq[x]){
                        ans.push_back(x+'a');
                        freq[x]--;

                        for(int i=0; i<26; i++){
                            if(freq[i]) {
                                ans.append(freq[i], i+'a');
                                if(ans.size()==len) {
                                       string rev=ans;
                                     if(oddChar != '{') ans.push_back(oddChar);
                                   
                                     reverse(rev.begin(), rev.end());
                                     return ans+rev;
                                }
                            }
                        }

                        
                        


                     }


                  }




        }

        return "";











        




    }
};