class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pqBusy;
        set<int>availServers;

        vector<int>reqHandle(k,0);
       

        for(int i=0; i<k; i++){
            availServers.insert(i);
        }
        int t=0;
        int currI=0;

        for(int i=0; i<arrival.size(); i++){
            t=arrival[i];
            int duration=load[i];
            while(!pqBusy.empty() && pqBusy.top().first<=t){
                auto [time, id]=pqBusy.top();
                availServers.insert(id); 
                pqBusy.pop();
            }
            if(availServers.size()==0) continue;

            int target=i%k;
             auto it = availServers.lower_bound(target);

            if(it==availServers.end()) {
                it=availServers.begin();
            }

            pqBusy.push({t+duration,*it});
             reqHandle[*it]++;
            availServers.erase(it);
           


           
           
        }


       
        int maxi=*max_element(reqHandle.begin(),reqHandle.end());
        vector<int>ans;
        for(int i=0; i<reqHandle.size(); i++){
            int x=reqHandle[i];
            if(x==maxi){
                ans.push_back(i);
            }
        }
        return ans;
       







        
    }
};