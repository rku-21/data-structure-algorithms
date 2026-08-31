class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        int n=nums.size();
        int ans=0;
        vector<int>vis(101,0);

        for(auto  num : nums){
            int start=num[0];
            int end=num[1];

            while(start <=end){
                if(!vis[start]){
                    ans++;
                    vis[start]=1;
                }
                start++;
            }
        }
        return ans;

        
    }
};