class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n=nums.size();
        vector<bool>present(51,false);
        int sum=nums[0];
        for(int i=1; i<n; i++){
            if(nums[i]!=nums[i-1]+1) break;
            sum+=nums[i];
        }

        for(int i=0; i<n; i++) present[nums[i]]=true;
        if(sum>50) return sum;
        for(int i=sum; i<51; i++){
            if(!present[i]) return i;
            
        }
        return 51;
        






        
    }
};