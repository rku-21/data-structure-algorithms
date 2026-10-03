class Solution {
public:
    int n;
    bool canTake(int mask , string&a){
        vector<int>vis(26, 0);
        for(int i=0; i<a.size(); i++){
            int index = a[i]-'a';
            if(vis[index]) return false;
            vis[index]=1;
            if(mask & (1<<index)) return false;

        }
        return true;
    }
    int createMask(int mask , string&a){
        for(int i=0; i<a.size(); i++){
             int index = a[i]-'a';
            mask = mask | (1 << index);
        }
        return mask;
    }

    int solve(int idx, auto&arr, int currMask){
        if(idx>=n)  {
            int ans=0;
            for(int i=0; i<26; i++){
                  if(currMask & (1<<i)) ans++;

            }
            return ans;

        }

        int skip = solve(idx+1, arr, currMask);
        int take=0;

        if(canTake(currMask, arr[idx])){
            take= solve(idx+1, arr, createMask(currMask, arr[idx]));

        }

        return max(take, skip);
    }
    int maxLength(vector<string>& arr) {
        n=arr.size();

        return solve(0, arr,0);





    }
};