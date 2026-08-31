class Solution {
public:
    int mod=1e9+7;
    typedef long long ll;
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {

        int lasthCuts=0;
        int width=INT_MIN;
        int height=INT_MIN;
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        for(int i=0; i<horizontalCuts.size(); i++){
            height=max(height, horizontalCuts[i]-lasthCuts);
            lasthCuts=horizontalCuts[i];
            
        }
        height=max(height, h-lasthCuts);
        int lastvCuts=0;

        for(int i=0; i<verticalCuts.size(); i++){
            width=max(width, verticalCuts[i]- lastvCuts);
            lastvCuts=verticalCuts[i];
        }
        width=max(width, w-lastvCuts);
        cout<<height<<" "<<width<<endl;

        return ((ll)(height%mod)*(width%mod))%mod;

        
    }
};