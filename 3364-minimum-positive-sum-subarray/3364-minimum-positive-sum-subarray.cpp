class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {

        int ans=-1;
        int n=nums.size();
       

       for(int i=0; i<n; i++){
        int sum=0;
          for(int j=i; j<n; j++) {
              int len=j-i+1;
              sum+=nums[j];
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