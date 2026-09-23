class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();

        int l=0;
        int start=-1;
        int end=-1;
        int sum=0;
        for(int i=0; i<n;  i++){
            sum+=nums[i];

        }
        int target=sum-x;
        if(target<0) return -1;
       
        int currSum=0;
        for(int r=0; r<n; r++){
            currSum+=nums[r];
            while(currSum > target){
                currSum-=nums[l];
                l++;
            }
            if(currSum==target){
                if(start==-1){
                    start=l;
                    end=r;
                    
                }
                else if( r-l+1  > end-start+1){
                    start=l;
                    end=r;
                }
            }

        }

        if(start==-1) return -1;
        return n-(end-start+1);




        
    }
};