class Solution {
public:
    int minOperations(string s) {
        int n=s.size();
        string temp=s;
        sort(temp.begin(),temp.end());

        if(temp==s) return 0;
        if(n==2) return -1;
        char minCh='#';
        char maxCh='#';
        for(int i=0; i<n; i++){
            char ch=s[i];
            if(minCh=='#' || ch<minCh) {
                minCh=ch;
            }
            if(maxCh=='#' || ch>maxCh){
                maxCh=ch;
            }
        }
        if(s[0]==minCh || s[n-1]==maxCh) return 1;

        bool extraMinCh=false;
        bool extraMaxCh=false;
        for(int i=0; i<n; i++){
            if(i>0 && s[i]==maxCh) {
                extraMaxCh=true;
            }
            if(i<n-1 && s[i]==minCh){
                extraMinCh=true;
            }
        }
        if(s[0]==maxCh && s[n-1]==minCh && !extraMaxCh && !extraMinCh) return 3;

        return 2;

      
       

        














        
    }
};