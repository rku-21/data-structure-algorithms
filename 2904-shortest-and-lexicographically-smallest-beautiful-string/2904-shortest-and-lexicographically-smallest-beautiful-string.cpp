class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n=s.size();
        int one_cnt=0;
        int l=0;
        int len=INT_MAX;

        for(int r=0; r<n; r++){
            if(s[r]=='1') one_cnt++;

            while(one_cnt==k){
                len=min(r-l+1,len);
                if(s[l]=='1') one_cnt--;
                l++;

            }
        }
        // cout<<len<<endl; correct 
        if(len==INT_MAX) return "";
        one_cnt=0;
        for(int i=0; i<len; i++){
            if(s[i]=='1') one_cnt++;
        }
        // cout<<one_cnt<<endl; correct 
         string ans="";
         if(one_cnt==k) ans=s.substr(0,len);
        l=0;
        for(int r=len; r<n; r++){
            if(s[r]=='1') one_cnt++;
            if(s[l]=='1'){
                one_cnt--;
              
            }
            l++;

            if(one_cnt==k){
                // cout<<l<<" "<<r<<endl;
                string temp=s.substr(l,r-l+1);
                if(ans=="" || temp<ans){
                    ans=temp;
                }
            }



        }

        return ans;










        
    }
};