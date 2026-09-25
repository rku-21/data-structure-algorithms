class Solution {
public:
    int n;
    string s;
    int idx=0;

    set<string> getUnit(){
        set<string> res;

        if(s[idx]=='{'){
            idx++;
            res=doUnion();

        }
        else {
            // alpha 
            res= {string(1, s[idx])};

        }
        idx++;
        return res;
        
    }

    set<string> doConcate(){
        set<string> res={""};
        while(idx<n && isalpha(s[idx]) || s[idx]=='{'){
            set<string> temp=getUnit();

            set<string> conCateRes;
            for(auto left : res){
                for(auto right : temp){
                    conCateRes.insert(left+right);
                }
            }
            res=conCateRes;
        }
        return res;
    }

    set<string> doUnion(){
        set<string> res;
        while(idx <n){

            auto st= doConcate();
            res.insert(st.begin(), st.end());

            if(idx < n && s[idx]==','){
                idx++;
            }
            else break;


        }

        return res;


    }
    vector<string> braceExpansionII(string expression) {
        n=expression.size();
        s=expression;
        idx=0;

        set<string> ans=doUnion();

        return vector<string>(ans.begin(), ans.end());
        
    }
};