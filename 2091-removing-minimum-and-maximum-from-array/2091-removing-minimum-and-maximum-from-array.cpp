class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return 1;
        int maxi=INT_MIN;
        int mini=INT_MAX;
        int min_pos=INT_MAX;
        int max_pos=INT_MAX;

        for(int i=0; i<n; i++){
            if(nums[i]>maxi){
                min_pos=i;
                maxi=nums[i];
            }
            if(nums[i]<mini){
                max_pos=i;
                mini=nums[i];
            }

        }

        int ans=0;
        int l=0;
        int r=n-1;
        int ld=min(min_pos+1, max_pos+1);
        int rd=min(r-min_pos+1, r-max_pos+1);
       

        if(ld<=rd){
            ans+=ld;
            l=ld;
        }
        else {
            ans+=rd;
            r-=rd;
        }
        if(min_pos < l  || min_pos > r){
            return ans+=min(max_pos-l+1, r-max_pos+1);
        }

        return ans+=min(min_pos-l+1, r-min_pos+1);
















        
    }
};