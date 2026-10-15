class Solution {
public:
   int distinct_cnt(int i, int j, auto&nums){
    int cnt=0;
     vector<int>seen(101,0);
      while(i<=j){
        if(!seen[nums[i]]) cnt++;
        seen[nums[i]]=1;
         i++;
      }
      return cnt;
   }
    int sumCounts(vector<int>& nums) {
        int n=nums.size();
        int ans=0;

        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                int cnt=distinct_cnt(i,j,nums);
                ans+=cnt * cnt;
            }

        }
        return ans;

        
    }
};