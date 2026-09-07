class Solution {
public:
    int inf=INT_MAX;
    int n;
    int dp[101][5001];
    int solve(int idx, auto& store,int sum){
        if(sum==0) return 0;
        if(idx>=n) return inf/2;
        if(dp[idx][sum]!=-1) return dp[idx][sum];
        int ans=inf/2;
        ans=min(ans, solve(idx+1,store,sum));

        for(auto p: store[idx]){
            int num=p.first;
            int ops=p.second;
            if(sum-num>=0){
                ans=min(ans,ops+solve(idx+1, store,sum-num));
               
            }
           

        }
        return dp[idx][sum]=ans;


    }
    int minOperations(vector<int>& nums, int sum) {
        n=nums.size();
        int maxi=*max_element(nums.begin(), nums.end());

        vector<vector<int>>tempStore(n, vector<int>(sum+1,inf));

        for(int i=0; i<n; i++){
             
             vector<bool>vis(max(sum+1, maxi+1),false);

            queue<pair<int,int>>q;
            q.push({nums[i],0});
            if(nums[i]<=sum)  vis[nums[i]]=true;

            while(!q.empty()){
                auto [num ,ops]=q.front();
                q.pop();
               if(num <=sum ){
                     tempStore[i][num]=ops;
               }




                if(num * 2 <= max(sum, maxi) && vis[num*2]==false){
                    q.push({num*2, ops+1});
                    vis[num*2]=true;
                }
                if(vis[num/2]==false){
                     q.push({num/2,ops+1});
                     vis[num/2]=true; 
                }

            }
        }
        vector<vector<pair<int,int>>>store(n);
        for(int i=0; i<n; i++){
            auto& v=tempStore[i];
            for(int j=0; j<=sum; j++){
                if(v[j]!=inf){
                    store[i].push_back({j, v[j]});

                }
            }
        }
        memset(dp, -1,sizeof(dp));


        int ans=solve(0, store, sum );
        if(ans<inf/2) return ans;
        return -1;




        




        
    }
};