class Solution {
    typedef long long ll;
    const int maxi =1e5;

public:
 long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n=nums1.size();

        vector<ll>diffCnt(maxi+1,0);

        for(int i=0; i<n; i++){
            int d= abs(nums1[i]-nums2[i]);
            diffCnt[d]++;
        }

        ll tOps= k1+k2;

        for(int i=maxi; i>0; i--){
            if(diffCnt[i]==0) continue;

            int used = min(tOps, diffCnt[i]);
            diffCnt[i]-=used;
            diffCnt[i-1]+=used;
            tOps-=used;
        }


        ll ans=0;
        for(ll i=1; i<=maxi; i++){
            if(diffCnt[i]==0) continue;

            ans = ans + diffCnt[i] * (i * i);
        }

        return ans;



       



        
    }
};