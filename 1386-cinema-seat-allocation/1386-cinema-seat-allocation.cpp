class Solution {
public:
    int currGroupCnt(auto&blockSeats){
        int ans=0;
        bool allempty=true;
        for(int i=2; i<6; i++){
            if(blockSeats[i]==1) allempty=false;
        }
        if(allempty) {
            ans=1;
        }
        allempty=true;


       

        for(int i=4; i<8; i++){
            if(blockSeats[i]==1) allempty=false;
        }
        if(allempty) ans=1;

        allempty=true;

        for(int i=6; i<10; i++){
            if(blockSeats[i]==1) allempty=false;
        }
        
        if(allempty) ans=1;
        allempty=true;
        for(int i=2; i<=9; i++){
            if(blockSeats[i]==1) allempty=false;
        }
        if(allempty) return 2;
        return ans;
        
       
    }
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int m=reservedSeats.size();

        sort(reservedSeats.begin(), reservedSeats.end());

        int ans=0;
        int lastRow=0;
        int i=0;
        while(i<m){
            int currRow=reservedSeats[i][0];
            if(currRow != lastRow) ans+=(currRow-lastRow-1)*2;

            vector<int>blockSeats(11,0);
            while( i<m && reservedSeats[i][0] == currRow){
                int seat=reservedSeats[i][1];
                blockSeats[seat]=1;

                i++;
            }

            //  cnt for the currRow 
            ans+=currGroupCnt(blockSeats);





            lastRow=currRow;
        }
        ans+=(n-lastRow)*2;

        return ans;

        



        
        
    }
};