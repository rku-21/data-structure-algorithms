class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n=word.size();
        int smallMask=0;
        int bigMask=0;

        for(auto ch : word){
            if(ch>='A' && ch<='Z') {
                int idx=ch-'A';
                bigMask |= (1<<idx);
            }
            else {
                int idx=ch-'a';
                smallMask |= (1<<idx);
            }
        }
        int ans=0;
        for(int bit=0; bit<26; bit++){
            if((bigMask & (1<<bit)) && (smallMask & (1<<bit))) {
                 ans++;
            }
        }
        return ans;
        
        
    }
};