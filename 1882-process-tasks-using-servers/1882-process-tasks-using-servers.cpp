class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n=servers.size();
        int m=tasks.size();
        vector<int>ans;

        long long  currTime=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pqFree;
        priority_queue<tuple<long long ,int,int>,vector<tuple<long long ,int,int>>,greater<tuple<long long,int,int>>>pqLocked;

        for(int i=0; i<n; i++){
            pqFree.push({servers[i],i});
        }
        for(int i=0; i<m; i++){
            int task=tasks[i];
            currTime=max(currTime,1LL*i);

             if (pqFree.empty()) {
                currTime = max(currTime, get<0>(pqLocked.top()));
            }

            while(!pqLocked.empty() && get<0>(pqLocked.top())<=currTime) {
                pqFree.push({get<1>(pqLocked.top()), get<2>(pqLocked.top())});
                pqLocked.pop();

            }
             ans.push_back(pqFree.top().second);
            pqLocked.push({currTime + task, pqFree.top().first, pqFree.top().second});
            pqFree.pop();
            


        }
        return ans;
        






    }
};