class Solution {
public:
    vector<vector<string>> findMismatchedSegments(string s1, string s2) {
        int n=s1.size();
        int l=0;
        vector<vector<string>>ans;
        int i=0;
        while(i<n){
            if(s1[i]==s2[i]) {
                i++;
            }
            else {
                l=i;
                while(i<n && s1[i]!=s2[i]) i++;
                ans.push_back({s1.substr(l,i-l),s2.substr(l,i-l)});
            }
        }
        
        return ans;

        
    }
};