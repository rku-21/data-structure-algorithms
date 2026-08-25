class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        sort(begin(nums), end(nums));
        int n=nums.size();
        int temp=k;

        for(int i=0; i<n; i++){
            if(nums[i]<k) continue;
            if(nums[i]==k){
                k+=temp;
            
            }
            else return k;



        }
        return k;
        
    }
};