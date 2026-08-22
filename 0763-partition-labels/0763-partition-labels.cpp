class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n=s.size();

        vector<int>ans,first(26,-1),last(26,-1);
        int i=0;
        for(int i=0; i<n; i++){
            int idx=s[i]-'a';
            if(first[idx]==-1) {
                first[idx]=i;
            }
            last[idx]=i;
            
        }

        while(i<n){

            int idx=s[i]-'a';
            int end=last[idx];
            int max_size=end-i+1;
            int j=i;
            for(j=i+1; j<=end; j++){
                int newEnd=last[s[j]-'a'];
                if(newEnd<=end) continue;
                end=newEnd;
                max_size=newEnd-i+1;

            }

            ans.push_back(max_size);
            i=j;
            



            
        }

        return ans;







       
        
    }
};