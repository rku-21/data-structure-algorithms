class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int n) {
        int mask=0;
        for(int i=0; i<8; i++){
            if(cells[i]==1){
                mask=mask | (1<<i);
            }
        }

        unordered_map<int,int>mp;
        mp[mask]=0;

        vector<int>ans=cells;
        int repeted_mask=mask;

        cout<<mask<<endl;

        int days=1;
        ans[0]=ans[7]=0;
        while(days<=n){

            mask=0;

            for(int i=1; i<7; i++){
                if((cells[i-1]==0 && cells[i+1]==0) || (cells[i-1]==1 && cells[i+1]==1)){
                    mask= mask | (1<<i);
                    ans[i]=1;
                }
                else ans[i]=0;
            }
            // cout<<mask<<" at "<<days<<endl;
            if(days==n) return ans;
            if(mp.count(mask)){
                repeted_mask=mask;
                // cout<<"repeted"<<endl;
                break;
            }

            mp[mask]=days;
            days++;

            cells=ans;
        }
        int cycleLength=mp[repeted_mask]-days;

        int leftDays=n-days;

        int rem=leftDays % cycleLength;

        cells=ans;

        while(rem--){

             for(int i=1; i<7; i++){
                if((cells[i-1]==0 && cells[i+1]==0) || (cells[i-1]==1 && cells[i+1]==1)){
                  
                    ans[i]=1;
                }
                else ans[i]=0;
            }
            cells=ans;

        }

        return cells;






        


        
    }
};