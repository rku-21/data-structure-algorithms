class Solution {
public:
    typedef long long ll;
    ll gcd(ll a, ll b){
        if(b==0) return a;

        return gcd(b, a%b);
    }
    ll lcm(ll a , ll b){
        ll g=gcd(a,b);

        return a*b/g;
    }
    ll count(ll x, auto&coins){

        ll ans=0;
        int n=coins.size();

        for(int mask=1; mask <(1<<n); mask++){
            ll multiple=1;
            int bits=0;

            for(int i=0; i<n; i++){

                if((mask & (1<<i))!=0){
                    bits++;

                    multiple=lcm(multiple, coins[i]);



                }

                if(multiple >x) break;
            }

            if(multiple > x) continue;

            ll value=x/multiple;

            if(bits%2==0){
                ans-=value;
            }
            else ans+=value;


        }

        return  ans;


    }
    long long findKthSmallest(vector<int>& coins, int k) {

        ll low=1;
        ll high=*min_element(coins.begin(),coins.end())*1LL*k;

        while(low<high){
            ll mid=low+(high-low)/2;

            if(count(mid, coins)<k){
                low=mid+1;

            }
            else high=mid;
        }

        return low;


        
    }
};