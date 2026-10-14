class Solution {
public:
    string maxSumOfSquares(int num, int sum) {

        string ans="";
        int currdigit=9;
        while(num>0){
            currdigit=min(currdigit,sum);
            ans.push_back('0'+currdigit);
            num--;
            sum-=currdigit;
        }
        if(sum!=0) return "";
        return ans;
        
    }
};