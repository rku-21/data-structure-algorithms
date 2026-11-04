class Solution {
public:
    int minimumLevels(vector<int>& possible) {
        int n=possible.size();
        int sum=0;
        for(int i=0; i<n; i++){
            int val= possible[i] ? 1: -1;
            sum+=val;
        }
        int currSum=0;
        int ans=0;
        for(int i=0; i<n-1; i++){
             int val= possible[i] ? 1: -1;
             currSum+=val;
             ans++;
             if(2*currSum > sum) {
                return ans;
             }

            
        }
        return -1;
        
    }
};