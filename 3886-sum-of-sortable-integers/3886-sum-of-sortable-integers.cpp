class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n=nums.size();

        set<int>st;
        int all=0;
        for(int i=1; i*i<=n; i++){
            if((n %i )==0){
                int a=i;
                int b=n/a;
                st.insert(a);
                st.insert(b);
              
              
            }

        }
        bool isSorted=true;
        for(int i=0; i<n-1; i++){
            if(nums[i]>nums[i+1]) {
                isSorted=false;
                break;
            }
                    
        }
        for(auto s : st){
            all+=s;
        }
        if(isSorted) return all;

        int ans=0;
        for(auto div : st){
           
            if(div==1) continue;
            bool ok=true;
            int prev_maxi= INT_MIN;
            for(int start=0; start<n; start+=div){
                int curr_min=INT_MAX;
                int curr_maxi=INT_MIN;

                int drop=0;
                for(int i=0; i<div; i++){
                    int curr_idx=start+i;
                    int next_idx = start + (i + 1) % div; 
                    if(nums[curr_idx]>nums[next_idx]) {
                        drop++;
                    }
                    curr_min=min(curr_min,nums[curr_idx]);
                    curr_maxi=max(curr_maxi, nums[curr_idx]);

                }


                if(drop>1 || prev_maxi> curr_min){
                    ok=false;
                    break;
                }
                prev_maxi=curr_maxi; 




            }
            if(ok){
                ans+=div;
            }
           
        }

        return ans;


        
    }
};