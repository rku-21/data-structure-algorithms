class Solution {
public:
    bool won(auto&board, char ch){
        string curr="";
      
        curr.append(3, ch);
      
        if(board[0]== curr || board[1]== curr || board[2] == curr){
            return true;
        }

        for(int i=0; i<3; i++){
            string temp="";
            for(int j=0; j<3; j++){
                temp.push_back(board[j][i]);
                
            }
            cout<<temp<<endl;
            if(temp == curr) return true;
        }
        string temp="";
        temp.push_back(board[0][0]);
        temp.push_back(board[1][1]);
        temp.push_back(board[2][2]);

      if(temp == curr) return true;

        temp ="";

        temp.push_back(board[2][0]);
        temp.push_back(board[1][1]);
        temp.push_back(board[0][2]);

        return curr == temp;
         

    }
    bool validTicTacToe(vector<string>& board) {

        int n=board.size();
        int cnto,cntx;
        cnto=cntx=0;

        for(auto b : board){
            for(int i=0; i<b.size(); i++){
                if(b[i]=='X') cntx++;
                else if(b[i]=='O') cnto++;
            }
        }

        if(cnto > cntx) return false;

        if(cntx > cnto+1) return false;

        //  both won 
        bool isxwon = won(board, 'X');
        bool isowon = won(board, 'O');
        cout<<isxwon<<" "<<isowon<<endl;
        if(isxwon && isowon) return false;
        if(isxwon && cntx !=cnto +1) return false;
        if(isowon && cntx != cnto) return false;

        return true;






        
    }
};