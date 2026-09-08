class Solution {
public:
    int solve(int n){
        int cnt=0;
        int ans=0;
        while(n){
            if(cnt==3) {
                ans++;
                cnt=0;
            }
            else cnt++;
            
            n/=10;
        }
        return ans;
    }
    int countCommas(int n) {
        if(n<=999) return 0;

        int ans=0;
        int start=1000;
        while(start<=n){
            
            ans+=solve(start);
            start++;
        }
        return ans;





        
    }
};