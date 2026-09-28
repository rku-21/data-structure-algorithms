class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int n=seq.size();
        int cntA,cntB;
        cntA=cntB=0;
        vector<int>ans;

        for(int i=0; i<n; i++){
            bool inA=true;
            if(seq[i]=='('){
                if(cntA <=cntB) cntA++;
                else {
                    cntB++;
                    inA=false;
                }
            }
            else {
                if(cntA >=cntB) cntA--;
                else {
                    cntB--;
                    inA=false;
                }

            }
            if(inA){
                ans.push_back(0);

            }
            else ans.push_back(1);
            
        }

        return ans;
        
    }
};