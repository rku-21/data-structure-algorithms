class Solution {
public:
  int n;
  typedef pair<int,vector<int>> P;
    
    pair<int,vector<int>> solve(int idx, auto&prefSum, int k,int rem,auto&dp){
        if(rem==0) return {0,{}};
        if(idx+k >n) return {-1e9,{}}; // invalid path
        if(dp[idx][rem].first!= -1e9) return dp[idx][rem];

        int sum=prefSum[idx+k]-prefSum[idx];
        auto skip=solve(idx+1, prefSum ,k, rem,dp);
        auto take=solve(idx+k, prefSum, k, rem-1,dp);
        pair<int,vector<int>> result;
        vector<int>takeindices;
        takeindices.push_back(idx);
        takeindices.insert(takeindices.end(),take.second.begin(), take.second.end());

        if(sum+take.first >= skip.first) {
            result = {sum+take.first, takeindices};
        }
        else {
            result= skip;
        }
        return dp[idx][rem]=result;
    }
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        n=nums.size();
        vector<int>prefSum(n+1,0);
        for(int i=1; i<=n; i++){
            prefSum[i]=prefSum[i-1]+nums[i-1];
        }
        vector<vector<P>>dp(n+1,vector<P>(5,{-1e9,{}}));

        return solve(0,prefSum, k, 3,dp).second;
        
    }
};