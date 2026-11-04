class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();

        vector<double>ans;
        multiset<long long>left,right;
        for(int i=0; i<n; i++){
            int num=nums[i];
            if(left.empty() || num <= *left.rbegin()) {
                left.insert(num);
            }
            else {
                right.insert(num);
            }
            if(i-k>=0) {
                int temp=nums[i-k];
                if(temp <= *left.rbegin()) {
                    left.erase(left.find(temp));
                }
                else right.erase(right.find(temp));

            }
            if(left.size()>right.size()+1){
                auto it=prev(left.end());
                right.insert(*it);
                left.erase(it);
            }
            else if(right.size()> left.size()) {
                auto it=right.begin();
                left.insert(*it);
                right.erase(it);
            }

            if(i>=k-1){
                if(k % 2==1){
                    ans.push_back(*left.rbegin());
                }
                else  {
                    ans.push_back((*left.rbegin()+*right.begin())/2.0);
                }
            }

            




        }
        return ans;

        
    }
};