class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans=INT_MAX;
        int n=nums.size();

        bool first=true;
        for(int i=0; i<n; i++){
            if(nums[i]!=(nums[0]+i)%n){
                first=false;
                break;
            }
        }

        if(first){
            int s=nums[0];
            ans=min(ans,(n-s)%n);
            ans=min(ans,s+2);
        }

        bool second=true;
        for(int i=0; i<n; i++){
            if(nums[i]!=((nums[0]-i)%n+n)%n){
                second=false;
                break;
            }
        }

        if(second){
            int t=n-1-nums[0];
            ans=min(ans,t+1);
            ans=min(ans,n-t+1);
        }
        return ans==INT_MAX?-1:ans;
        
        
        
    }
};