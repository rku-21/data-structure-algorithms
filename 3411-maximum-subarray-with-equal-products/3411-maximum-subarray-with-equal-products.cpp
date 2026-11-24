class Solution {
public:
    bool ok(int l, int r, auto&nums){
        long long  p=1;
        int lm=nums[l];
        int gd=nums[l];
        for(int i=l; i<=r; i++){
            if(p>1e12) return false;
            p=p*1LL*nums[i];
            lm=lcm(lm, nums[i]);
            gd=__gcd(gd, nums[i]);
        }
        return p==1LL*lm * gd;

    }
    int maxLength(vector<int>& nums) {
        int n=nums.size();
        int ans=0;

        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++) {
                if(ok(i,j, nums)) {
                    ans=max(ans, j-i+1);
                }
            }
        }
        return ans;


        
    }
};