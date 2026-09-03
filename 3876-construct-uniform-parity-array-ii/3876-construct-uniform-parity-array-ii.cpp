class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n=nums1.size();

        int miniOdd=INT_MAX;
        for(int i=0; i<n; i++){
            if(nums1[i]&1){
                miniOdd=min(nums1[i], miniOdd);
            }
        }
        if(miniOdd==INT_MAX) return true;

        bool isOdd=true;

        for(int i=0; i<n; i++){
            if(nums1[i]&1) continue;

            int num = nums1[i];

            if(num < miniOdd) {
                isOdd=false;
                break;
            }
        }

        return isOdd;



       


        
    }
};