class Solution {
public:
    int totalNumbers(vector<int>& digits) {

        int ans=0;
        int n=digits.size();
        vector<int>vis(1000,0);

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                for(int k=0; k<n; k++){
                    if(i!=j && j!=k && i!=k){
                        int num=0;
                        num=num*10+digits[i];
                        num=num*10+digits[j];
                        num=num*10+digits[k];
                        if(vis[num]) continue;

                        if(num %2==0 && num>=100 && num<=999) ans++; 
                        vis[num]=1;
                    }
                }
            }
        }
        return ans;

       
        
    }
};