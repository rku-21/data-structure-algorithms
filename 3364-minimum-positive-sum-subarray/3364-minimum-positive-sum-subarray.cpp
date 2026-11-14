class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {

        int ans=-1;
        int n=nums.size();
        vector<int>prefSum(n+1,0);
        prefSum[0]=0;
        for(int i=1; i<=n; i++){
            prefSum[i]=prefSum[i-1]+nums[i-1];
        }


       for(int i=0; i<n; i++){
          for(int j=i; j<n; j++) {
              int len=j-i+1;
              int sum=prefSum[j+1]-prefSum[i];
              if(len>=l && len<=r && sum>0 ){
                if(ans==-1 || sum<ans) {
                    ans=sum;
                }

                
              }
          }
       }
       return ans;



        
        
    }
};