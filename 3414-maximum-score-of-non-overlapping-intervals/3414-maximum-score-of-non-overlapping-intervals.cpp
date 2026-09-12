class Solution {
public:
   int n;

   struct Node {
        long long score=-1;
        vector<int>idxs;
    };
    vector<vector<Node>>dp;

    Node solve(auto&intervals, int idx ,int k, auto&nextIdx) {

        if(k==0 || idx>=n) return Node();

        if(dp[idx][k].score != -1) return dp[idx][k];

        int weight=intervals[idx][2];
        int originalPos=intervals[idx][3];
        int j=nextIdx[idx];


        Node skip = solve(intervals, idx+1, k, nextIdx);

        Node temp = solve(intervals, j , k-1, nextIdx);

        Node take;

        take.score=temp.score + weight;
        take.idxs=temp.idxs;
        take.idxs.push_back(originalPos);
        sort(take.idxs.begin(), take.idxs.end());

        if(skip.score > take.score) return dp[idx][k]=skip;

        if(take.score > skip.score) return dp[idx][k]=take;

        Node result = take.idxs > skip.idxs ? skip : take;

        return dp[idx][k]=result;


}

   int findNext(auto&intervals, int endPoint, int idx){
     int start=idx+1;
     int end=n-1;
     int ans=n;

     while(start <=end){
        int mid = start + (end - start)/2;

        if(intervals[mid][0] >  endPoint) {
            ans=mid;
            end=mid-1;

        }
        else start=mid+1;

     }

     return ans;
       
      

   }

 

    
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        n=intervals.size();

        for(int i=0; i<n; i++){
            intervals[i].push_back(i);
        }

        sort(intervals.begin(), intervals.end(), [&](const auto&a, const auto&b){
            return a[0] < b[0];
        });

        vector<int>nextIdx(n);
        for(int i=0; i<n; i++){

            int endpoint=intervals[i][1];
            nextIdx[i]=findNext(intervals, endpoint, i);
        }

         dp.assign(n+1, vector<Node>(5));

        return solve(intervals, 0, 4,nextIdx).idxs;








        
    }
};