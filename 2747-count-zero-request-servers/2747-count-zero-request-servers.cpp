class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        sort(logs.begin(),logs.end(),[](const auto&a, const auto&b){
            return a[1]<b[1];
        });


        vector<pair<int,int>>sortedQueries;
        for(int i=0; i<queries.size(); i++){
            sortedQueries.push_back({queries[i],i});
        }

        sort(sortedQueries.begin(),sortedQueries.end());

        vector<int>ans(queries.size());


        int l=0;
        int r=0;
        int activeServers=0;
        vector<int>serverFreq(n+1,0);
        for(auto q:sortedQueries){
            int start=q.first-x;
            int end=q.first;

            while(r<logs.size() && logs[r][1]<=end){
                int serverId=logs[r][0];
                if(serverFreq[serverId]==0){
                    activeServers++;
                }
                serverFreq[serverId]++;
                r++;
            }
            while(l<logs.size() && logs[l][1]<start){
                int serverId=logs[l][0];
                 if(serverFreq[serverId]>0) serverFreq[serverId]--;
                if(serverFreq[serverId]==0){
                    activeServers--;
                }
                l++;
            }

            ans[q.second]=n-activeServers;

          

        }
        return ans;



        
    }
};