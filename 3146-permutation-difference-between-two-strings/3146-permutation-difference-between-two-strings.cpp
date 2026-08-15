class Solution {
public:
    int findPermutationDifference(string s, string t) {
        int n=s.size();
        vector<int>pos(26,-1);
        for(int i=0; i<n; i++){
            int idx=t[i]-'a';
            pos[idx]=i;
        }
        int sum=0;

        for(int i=0; i<n; i++){
            int idx=s[i]-'a';
            sum+=abs(i-pos[idx]);
        }

        return sum;



        
        
    }
};