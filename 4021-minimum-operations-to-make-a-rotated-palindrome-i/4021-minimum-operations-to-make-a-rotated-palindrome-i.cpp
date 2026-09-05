class Solution {
public:
    int palin(string s){
        int n=s.size();
        // cout<<s<<endl;
        
        int i=0; 
        int j=n-1;
        int ans=0;
        while(i<j){
            if(s[i]==s[j]) continue;
            int idx1=s[i]-'a';
            int idx2=s[j]-'a';
            if(idx1<idx2){
                idx1=idx1^idx2;
                idx2=idx1^idx2;
                idx1^=idx2;
            }
            // cout<<idx1<<" "<<idx2<<endl;

            ans+=min(idx1-idx2 , 26-idx1+idx2);
            i++;
            j--;
        }

        return ans;
    }
    int minOperations(string s) {
        int n=s.size();

        int ans=INT_MAX;
        ans=min(ans, palin(s));

        for(int i=1; i<n; i++){
            ans=min(ans, i+palin(s.substr(i)+s.substr(0,i)));
        }

        return ans;


        
    }
};