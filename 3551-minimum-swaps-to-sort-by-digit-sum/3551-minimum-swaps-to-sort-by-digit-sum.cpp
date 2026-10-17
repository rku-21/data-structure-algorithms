class Solution {
public:
    int digitSum(int num){
        int sum=0;
        while(num){
            sum+=num %10;
            num/=10;
        }
        return sum;
    }
    int minSwaps(vector<int>& nums) {
        int n=nums.size();
        vector<pair<int,int>>store;
        unordered_map<int,int>mp;
        int i=0;
        for(auto num : nums){
            int s=digitSum(num);
            store.push_back({s,num});
            mp[num]=i;
            i++;
        }
        sort(store.begin(),store.end());

        int ans=0;
        for(int i=0; i<n; i++){
            int currNum=nums[i];
            int requiredNum=store[i].second;
            if(currNum==requiredNum) continue;
            int idx=mp[requiredNum];
            ans++;
            nums[i]=requiredNum;
            nums[idx]=currNum;
            mp[currNum]=idx;
        }
        return ans;
        
        
    }
};