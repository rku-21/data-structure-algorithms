class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n=arr.size();
        int ans=INT_MAX;
        int bestMin=INT_MAX;
        vector<int>minTillR(n, INT_MAX);
        int l=0;
        int sum=0;
        for(int r=0; r<n; r++){
            sum+=arr[r];

            while(l < r && sum > target){
                sum-=arr[l++];
            }

            if(sum == target){
                int len=r-l+1;

                if(l>0 && minTillR[l-1]!=INT_MAX){
                    ans=min(ans, minTillR[l-1]+len);
                }
                bestMin=min(bestMin, len);

            }
            minTillR[r]=bestMin;
        }
        if(ans==INT_MAX) return -1;
        return ans;
        
    }
};