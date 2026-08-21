class Solution {
public:
    bool isRobotBounded(string instructions) {
        int direction=0;
        int x=0;
        int y=0;
        for(auto s: instructions){
            if(s=='L'){
                direction=(direction+1)%4;

            }
            else if(s=='R') {
                direction=(direction-1+4)%4;
            }
            else {
                if(direction==0){
                    y++;
                }
                else if(direction==1){
                    x--;
                }
                else if(direction==2){
                    y--;
                }
                else x++;
            }
        }

        if(direction!=0) return true;
        if(x==0 && y==0) return true;
        return false;
        
    }
};