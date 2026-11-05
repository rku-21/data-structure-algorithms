class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(), arr2.end());
        int ans=0;

        for(auto x:arr1){

            auto it=lower_bound(arr2.begin(), arr2.end(),x);

            if(it==arr2.end()) it--;
            if(*it==x){
                if(d==0) ans++;
                continue;
            }
            int val1=*it;
            if(it!=arr2.begin()) it--;
            int val2=*it;
            if(abs(x-val1)>d && abs(x-val2)>d) ans++;

            
        }
        return ans;
        


        
    }
};