class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n=nums.size();

        vector<int>ans,arr1,arr2;
        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);

        int i=0;
        int j=0;
        for(int k=2; k<n; k++){
            if(arr1[i]>arr2[j]){
                arr1.push_back(nums[k]);
                i++;
            }
            else {
                arr2.push_back(nums[k]);
                j++;
            }

        }
        for(int i=0; i<arr1.size(); i++){
            ans.push_back(arr1[i]);
        }
        for(int j=0; j<arr2.size(); j++){
            ans.push_back(arr2[j]);
        }

        return ans;

        

        


        
    }
};