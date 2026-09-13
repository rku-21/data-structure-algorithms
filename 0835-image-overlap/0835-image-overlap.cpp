class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {

        int n=img1.size();
        int ans=0;

        vector<pair<int,int>>pic1,pic2;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(img1[i][j]==1) pic1.push_back({i,j});
                if(img2[i][j]==1) pic2.push_back({i,j});
            }
        }

        for(int i=0; i<pic1.size(); i++){
            for(int j=0; j<pic2.size(); j++){

                int x=pic1[i].first - pic2[j].first;
                int y=pic1[i].second - pic2[j].second;

                int tempAns=1;
                for(int k=0; k<pic1.size(); k++){
                    if(k==i) continue;
                    int newx=pic1[k].first - x;
                    int newy=pic1[k].second - y;

                    if(newx>=0 && newy>=0 && newx<n && newy<n && img2[newx][newy]==1){
                        tempAns++;
                        
                    }


                }

                ans=max(ans, tempAns);

                



            }
        }

        return ans;



       




        
    }
};