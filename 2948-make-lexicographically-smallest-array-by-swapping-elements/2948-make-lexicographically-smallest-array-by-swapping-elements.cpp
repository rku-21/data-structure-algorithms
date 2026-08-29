class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n=nums.size();

        vector<int>parent(n);
        vector<pair<int,int>>sortedPairs;
        for(int i=0; i<n; i++){
            parent[i]=i;
            sortedPairs.push_back({nums[i],i});
        }

        sort(begin(sortedPairs), end(sortedPairs));

        for(int i=0; i<n-1; i++){
            if(sortedPairs[i+1].first - sortedPairs[i].first <=limit) {
                parent[sortedPairs[i+1].second]=parent[sortedPairs[i].second];
            }
        }

        map<int,vector<int>>mp;
        for(int i=0; i<n; i++){
            mp[parent[i]].push_back(i);
        }

        vector<int>ans(n);

        for(auto m : mp){
            vector<int>temp;
            for(int i=0; i<m.second.size(); i++){
                temp.push_back(nums[m.second[i]]);
            }
            sort(temp.begin(), temp.end());
            for(int i=0; i<m.second.size(); i++){
                ans[m.second[i]]=temp[i];
            }


            
        }

        return ans;









        


    }
};