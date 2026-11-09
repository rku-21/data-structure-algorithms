class Solution {
public:
    int countSuffix(vector<int>& nums, vector<int>& target) {
        int n=target.size();
        int idx=n-1;
        
        while(idx>0 && target[idx]<=target[idx-1]) idx--;
        // cout<<idx<<endl;

        vector<int>prefMatch(n,0);
        prefMatch[0]=1;
        for(int i=1; i<n; i++){
            if(prefMatch[i-1] && nums[i-1]==target[i-1]){
                prefMatch[i]=1;
            }
            else break;
        }
        int ans=0;
        unordered_map<int,int>mp;
        for(int i=n-1; i>=idx; i--){
            mp[nums[i]]++;
            mp[target[i]]--;
            if(mp[nums[i]]==0) mp.erase(nums[i]);
            if(mp[target[i]]==0) mp.erase(target[i]);
            // cout<<mp.size()<<" "<<i<<endl;
            if(mp.empty() && prefMatch[i]) ans++;

        }
        return ans;

        
    }
};