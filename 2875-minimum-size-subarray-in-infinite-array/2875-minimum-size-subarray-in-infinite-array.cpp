class Solution {
public:
    int minSizeSubarray(vector<int>& nums, int target) {
        int n=nums.size();

        long long  arrSum=0;
        for(auto num : nums ){
           arrSum+=num;
        }

        int windowCnt = target / arrSum;
        int leftTarget = target % arrSum;
        if(leftTarget == 0) return windowCnt * n;

        int l=0;
        int currSum=0;
        int ans=INT_MAX;
        for(int r=0; r<2*n; r++){
            currSum+=nums[r %n];
            while(currSum > leftTarget){ 
                currSum-=nums[l %n];
                l++;

            }

            if(currSum == leftTarget){
                ans=min(ans, r-l+1);
            }
        }

        if(ans==INT_MAX) return -1;

        return windowCnt*n + ans;





        
    }
};