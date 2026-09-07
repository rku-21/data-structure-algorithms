class Solution {
public:
    typedef long long ll;
    int mod=1e9+7;
    int distinctSubseqII(string s) {
        int n=s.size();

        vector<ll>lastChar(26,0);

        for(auto ch :s){
            int idx= ch-'a';
            ll subseq=1;

            for(ll cnt : lastChar){
                subseq=(subseq+cnt)%mod;
            }
            lastChar[idx]=subseq;

        }

        ll ans=0;

        for(auto cnt : lastChar){
            ans=(ans+cnt)%mod;
        }

        return ans;
        
    }
};