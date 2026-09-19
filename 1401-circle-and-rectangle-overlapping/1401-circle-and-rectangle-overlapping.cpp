class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {

        int closeX=xCenter;
        if(xCenter < x1 ){
            closeX=x1;
        }
        else if(xCenter > x2){
            closeX=x2;
        }

        int closeY=yCenter;
        if(yCenter < y1){
            closeY=y1;
        }
        else if(yCenter > y2){
            closeY=y2;
        }

        int A=(xCenter - closeX) * (xCenter - closeX);
        int B=(yCenter - closeY) * (yCenter - closeY);

        int distance=sqrt(A+B);

        return distance <= radius;



       



    
        
    }
};