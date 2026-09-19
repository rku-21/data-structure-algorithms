class Solution {
public:
    string winningPlayer(int x, int y) {
        int temp = y / 4;
        int mini=min(x, temp);
        
        if(mini % 2 ==0) return "Bob";
        return "Alice";

        
    }
};