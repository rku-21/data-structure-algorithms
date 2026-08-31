class Solution {
public:
    int maxi=INT_MAX;
    int n;
    int dp[101][5001];
    int solve(int i, int sum, auto&store){
        if(sum==0) return 0;
        
        if(i>=n || sum<0) return maxi/2;
        if(dp[i][sum]!=-1) return dp[i][sum];
        int ans=INT_MAX/2;
           auto & v=store[i];
           for(auto t: v){
               int num=t.first;
               int cost=t.second;
               ans=min(ans, cost+solve(i+1, sum-num, store));
               ans=min(ans, solve(i+1, sum, store));
           }
           
        

        return dp[i][sum]=ans;




    }
    int minOperations(vector<int>& nums, int sum) {
       n=nums.size();

        vector<vector<pair<int,int>>>store(n);

        for(int i=0; i<n; i++){
            int num=nums[i];
            vector<pair<int,int>>tempStore;
            int ops=0;
            tempStore.push_back({num,0});
            if(num <=sum) store[i].push_back({num,0});
            while(num * 2 <=sum){
                num*=2;
                ops++;
                tempStore.push_back({num,ops});
                store[i].push_back({num,ops});
                
            }

            for(auto p : tempStore){
                int currOps=p.second;
                int num=p.first;
                while(num >1){
                    num/=2;
                    currOps++;
                  if(num <=sum) store[i].push_back({num,currOps});

                }
            }




        }
        memset(dp,-1,sizeof(dp));

        int ans=solve(0, sum, store);










        if(ans >=maxi/2) return -1;
        return ans;


        
    }
};