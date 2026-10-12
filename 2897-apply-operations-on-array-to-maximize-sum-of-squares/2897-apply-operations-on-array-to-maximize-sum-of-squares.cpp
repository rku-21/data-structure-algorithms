class Solution {
public:
    int mod=1e9+7;
    int maxSum(vector<int>& nums, int k) {
        int n=nums.size();

        vector<int>bitsCnt(32,0);
        for(auto num :nums){
            for(int bit=0; bit<32; bit++){
                if(num  & (1<<bit)) bitsCnt[bit]++;
            }
        }

        int ans=0;
        for(int i=0; i<k; i++){
            int temp=0;
            for(int bit=0; bit<32; bit++){
                if(bitsCnt[bit]>0){
                    temp = temp | (1<<bit);
                    bitsCnt[bit]--;
                }
            }
            if(temp==0) break;
            ans = (ans + (1LL*temp * 1LL*temp)%mod)%mod;
        }
        return ans;


        
    }
};