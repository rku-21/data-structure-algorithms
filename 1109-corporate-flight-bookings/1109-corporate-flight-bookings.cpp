class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int>ans(n);
        for(auto booking : bookings){
           int start = booking[0];
           int end=booking[1];
           int seats=booking[2];
           ans[start-1]+=seats;
          if(end<n) ans[end]-=seats;
        }

        for(int i=1; i<n; i++){
            ans[i]+=ans[i-1];
        }
        return ans;

        
    }
};