class Solution {
public:
     int n;
     string ans="";
     void solve(string&store , int idx, auto&target ,auto&freq, bool differ){
        if (differ ){
             string temp="";
             for(int i=0; i<26; i++){
                if(freq[i]>0){
                    temp.append(freq[i],i+'a');
                }
             }

             int oldsize=store.size();

             store+=temp;

             if(ans=="" || ans>store) ans=store;
             store.resize(oldsize);
             return;



        }
        if(idx>=n) return;
        int index=target[idx]-'a';

        for(int j=index; j<26; j++){

            if(freq[j]>0){

                store.push_back(j+'a');
                freq[j]--;

                if(j==index){
                    solve(store, idx+1, target ,freq, false);
                }
                else solve(store, idx+1, target, freq,true);

                store.pop_back();
                freq[j]++;



            }
        }
    }
    string lexGreaterPermutation(string s, string target) {
        n=s.size();
        vector<int>freq(26,0);
        for(int i=0; i<n; i++) freq[s[i]-'a']++;
        
        string temp="";
        // solve(temp, 0, target ,freq, false);
        // return ans;

        for(int i=0; i<n; i++){

            int idx=target[i]-'a';

            if(freq[idx]){
                 ans.push_back(idx+'a');
                 freq[idx]--;
                 continue;
            }
            else {
                 
                 for(int x=idx+1; x<26; x++){

                     if(freq[x]) {
                         ans.push_back(x+'a');
                         freq[x]--;

                         for(int i=0; i<26; i++){
                             ans.append(freq[i], i+'a');
                         }

                         return ans;


                     } 
                }

            }

             break; // need breakTrack 



        }

        for(int i=ans.size()-1; i>=0; i--) {
              int idx=ans[i]-'a';

              freq[idx]++;
              ans.pop_back();

            for(int x=idx+1; x<26; x++){

                     if(freq[x]) {
                         ans.push_back(x+'a');
                         freq[x]--;

                         for(int i=0; i<26; i++){
                             ans.append(freq[i], i+'a');
                         }

                         return ans;


                     }
            } 




             

        }

        return "";





        
        
    }
};