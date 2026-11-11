class Solution {
public:
    typedef long long ll;
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {

        ll ans1=min(need1,need2) * 1LL*costBoth;

        if(need1 > need2){
            ans1+=(need1-need2)*1LL*cost1;
        }
        else ans1+=(need2-need1)*1LL*cost2;

        ll ans2=need1 * 1LL*cost1 + need2 * 1LL*cost2;
        ll ans3=max(need1 , need2) * 1LL*costBoth;
        return min({ans1,ans2, ans3});





        
    }
};