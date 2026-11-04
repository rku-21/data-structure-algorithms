class Solution {
public:
    typedef long long ll;
    int n;
    ll dp[100001][20];
    ll solve(int idx, int x, auto&ops, int k){
        if(k<=0) return 0;
        if(idx+x>n) return 1e14;
        if(dp[idx][k]!=-1) return dp[idx][k];

        ll skip=solve(idx+1, x, ops, k);
         ll currOps=ops[idx+x-1];
        ll take=solve(idx+x, x, ops,k-1);

        return dp[idx][k]=min(skip, take+currOps);


    }
    long long minOperations(vector<int>& nums, int x, int k) {
        n=nums.size();

        vector<ll>window_ops(n,1e9);

        multiset<ll>left,right;
        ll lSum=0;
        ll rSum=0;

        for(int i=0; i<n; i++){
            int num=nums[i];

            if(left.empty() || num <= *left.rbegin()) {
                left.insert(num);
                lSum+=num;
            }
            else {
                right.insert(num);
                rSum+=num;
            }

            if(i>=x){
                int temp=nums[i-x];
                if(temp <= *left.rbegin()) {
                    left.erase(left.find(temp));
                    lSum-=temp;
                }
                else {
                    right.erase(right.find(temp));
                    rSum-=temp;
                }
            }

            if(left.size()> right.size()+1){
                auto it=prev(left.end());
                rSum+=*it;
                lSum-=*it;
                right.insert(*it);
                left.erase(it);
              
            }
            else if(right.size() > left.size()) {
                auto it=right.begin();
                left.insert(*it);
                lSum+=*it;
                rSum-=*it;
                right.erase(it);
                

            }

            if(i >= x-1){
                ll m=*left.rbegin();
                ll ops=m*(left.size()-right.size()) + (rSum - lSum);
                window_ops[i]=ops;
            }
        }
        memset(dp,-1,sizeof(dp));

        return solve(0,x,window_ops,k);



        
    }
};