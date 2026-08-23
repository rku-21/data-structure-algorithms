class Solution {
public:
    vector<bool> validSubarrays(vector<int>& nums, int k, vector<vector<int>>& queries) {

        int n=nums.size();
        vector<int>minR(n,n),maxR(n,-1);
        unordered_map<int,int>f1,f2;
        int d1=0;
       int d2=0;
       int  r1=0;
       int  r2=0;

        for(int l=0; l<n; l++){

            while(r1<n && d1<k){
                if(f1[nums[r1]]==0) d1++;
                f1[nums[r1]]++;
                r1++;
            }
            if(d1==k) minR[l]=r1-1;

            while(r2<n){
                if(f2[nums[r2]]==0 && d2==k) break;
                if(f2[nums[r2]]==0) d2++;
                f2[nums[r2]]++;
                r2++;
            }

          if(d2==k)  maxR[l]=r2-1;

          f1[nums[l]]--;
          if(f1[nums[l]]==0) {
            f1.erase(nums[l]);
            d1--;
          }
          f2[nums[l]]--;
          if(f2[nums[l]]==0) {
            f2.erase(nums[l]);
            d2--;
          }

        }
        mt19937_64 rng(1337); 
        unordered_map<int, unsigned long long> hmap;
        for (int x : nums) {
            if (hmap.find(x) == hmap.end()) hmap[x] = rng();
        }

       
        vector<unsigned long long> prefXor(n, 0);
        prefXor[0]=hmap[nums[0]];
        for (int i = 1; i < n; i++) {
            prefXor[i] = prefXor[i-1] ^ hmap[nums[i]];
        }



       

        vector<bool>ans;

        for(auto q:queries){
            int l=q[0];
            int r=q[1];

        bool hasK= r>=minR[l] && r<=maxR[l];
           unsigned long long sum=prefXor[r]-(l>0 ? prefXor[l-1]:0);
         

            if(hasK && sum==0){
                ans.push_back(true);
                
            }
            else ans.push_back(false);
            
        }

        return ans;

        

        

        
        
    }
};