class Solution {
public:
    int countGroups(vector<int>& position, vector<int>& speed, int distance) {
        int n=position.size();
        if(n<=1) return n;
        int ans=0;




        int pos=position[n-1];
        int sp=speed[n-1];
        for(int i=n-2; i>=0; i--){
            if(speed[i] > sp  || pos - position[i] <=distance){
                pos=position[i];
                continue;
            }
            ans++;
            sp=speed[i];
            pos=position[i];
           
           
        }
        return ans+1;
        
    }
};