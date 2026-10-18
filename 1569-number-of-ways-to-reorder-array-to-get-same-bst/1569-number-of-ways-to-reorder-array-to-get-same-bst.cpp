

class Solution {
public:
   typedef long long ll;
   
    int mod=1e9+7;
   static vector<vector<ll>>PT;
    static bool done;

    void compute() {
        if(done) return;
        PT.resize(1000,vector<ll>(1000,1));
        for(int row=2; row<1000; row++){
           int prevRow=row-1;
           for(int prevCol=0; prevCol<prevRow; prevCol++){
               PT[row][prevCol+1]=(PT[prevRow][prevCol]+PT[prevRow][prevCol+1])%mod;
           }
          
        }
        done=true;
    }
 
    ll solve(vector<int> nums){
        int n=nums.size();
        if(n<3) return 1;

        vector<int>left,right;
        int root=nums[0];

        for(int i=1; i<n; i++){
            if(nums[i]<root) {
                left.push_back(nums[i]);
            }else {
                right.push_back(nums[i]);
            }

        }

        ll x=solve(left)%mod;
        ll y=solve(right)%mod;
        int lsize=left.size();
        
        ll z=PT[n-1][lsize];

        return ((x*y)%mod *z)%mod;




    }
    int numOfWays(vector<int>& nums) {
        compute();
      

        return (solve(nums) -1 + mod ) %mod;
       




    }
};
vector<vector<Solution::ll>> Solution::PT;
bool Solution::done=false;