class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto e:edges){
            adj[e[0]].push_back({e[2],e[1]});
        }

        vector<vector<int>>dist(n,vector<int>(k+1,INT_MAX));

        dist[0][1]=0;
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        pq.push({0,0,1});

        while(!pq.empty()){
            auto top=pq.top();
            pq.pop();
            int distance=top[0];
            int node=top[1];
            int run=top[2];

            for(auto n:adj[node]){
                int neig=n.second;
                int weight=n.first;
                int newRun=1;
                if(labels[neig]==labels[node] && run>=k) continue;
                
                else if(labels[neig]==labels[node]){
                    newRun=run+1;
                }
                if(dist[neig][newRun]>distance+weight){
                    dist[neig][newRun]=distance+weight;
                     pq.push({distance+weight,neig,newRun});
                }

                
            }
            
            

            
        }
        int ans=INT_MAX;
        for(int i=0; i<=k; i++){
            ans=min(ans,dist[n-1][i]);
        }
        return ans==INT_MAX?-1:ans;
        

        

        

        
        
    }
};