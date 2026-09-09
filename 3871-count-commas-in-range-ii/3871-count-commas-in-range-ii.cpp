class Solution {
public:
    typedef long long ll;
    long long countCommas(long long n) {
        if(n<=999) return 0;

        ll ans=0;
        ll pow=1000;
        ll comma=1;
        while(pow <=n){
            ll nextNum=pow*1000-1;
            if(nextNum >n) {
                nextNum=n;
            }
            ans=ans+comma*(nextNum-pow+1);
            comma++;
            pow*=1000;
        }
        return ans;
        
    }
};