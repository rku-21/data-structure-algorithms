class Solution {
public:
    int n;
    bool stoneGameIX(vector<int>& stones) {
        n=stones.size();

        int zero=0;
        int one=0;
        int two=0;
        for(auto stone : stones){
            if(stone%3 == 0) zero++;
            else if(stone%3==1) one++;
            else {
                two++;
            }
        }

        if(zero %2==0){
            return one >=1 && two >=1;
        }

        return one - two >2 || two -one>2;


       
        
    }
};