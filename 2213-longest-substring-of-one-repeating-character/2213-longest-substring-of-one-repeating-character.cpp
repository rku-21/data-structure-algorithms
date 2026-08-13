class Node {
    public :
    char leftChar;
    char rightChar;
    int best;
    int pref;
    int suff;
    int len;
};
class SegmentTree {
    public:
    int n;
    vector<Node>segment;

    SegmentTree(int n , string s ){
        segment.resize(4*n);
        this->n=n;

        buildTree(0,0,n-1,s);
    }

    void  merge(int i , Node left, Node right){
         int iskaBest= left.suff+ right.pref;
          segment[i].pref = left.pref;
          segment[i].suff = right.suff;
       
        segment[i].best=max(iskaBest,segment[i].best);

            if( left.len ==  left.pref){
                segment[i].pref=left.len + right.pref;

            }
            if( right.len == right.suff){
                segment[i].suff=right.len + left.suff;
            }

    }

    void buildTree(int i, int l, int r, auto&s){
        if(l==r){
            segment[i].leftChar=segment[i].rightChar=s[l];
            segment[i].best=segment[i].pref=segment[i].suff=segment[i].len=1;
            return;



        }
        int mid=(l+r)/2;
        buildTree(2*i+1, l, mid, s);
        buildTree(2*i+2, mid+1,r, s);

        Node left=segment[2*i+1];
        Node right=segment[2*i+2];

         int leftBest= left.best;
         int rightBest= right.best;
         


         segment[i].best=max(leftBest,rightBest);
        if( left.rightChar ==  right.leftChar){
            merge(i, left, right);
           
           
        }
        else {
            segment[i].pref=left.pref;
            segment[i].suff=right.suff;
        }

        segment[i].len=left.len + right.len;
        
        segment[i].leftChar=left.leftChar;
        segment[i].rightChar=right.rightChar;
    }

    void update(int i ,int l, int r, int idx, char ch){
        if(l==r) {
            segment[i].leftChar=ch;
            segment[i].rightChar=ch;
            return;
        }

        int mid=(l+r)/2;

        if(idx<=mid){
            update(2*i+1, l, mid, idx, ch);
        }
        else {
            update(2*i+2, mid+1, r, idx , ch);
        }

        Node left=segment[2*i+1];
        Node right=segment[2*i+2];

         int leftBest= left.best;
         int rightBest= right.best;
         


         segment[i].best=max(leftBest,rightBest);



        if(left.rightChar == right.leftChar){
            merge(i, left, right);


        }
        else {
             segment[i].pref=left.pref;
            segment[i].suff=right.suff;
        }
        segment[i].len=left.len + right.len;
        
        segment[i].leftChar=left.leftChar;
        segment[i].rightChar=right.rightChar;
    }
};

class Solution {
public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {

        vector<int>ans;
        int slen=s.size();
        int n=queryIndices.size();
      
        SegmentTree tree(slen , s);
          cout<<tree.segment[0].best<<endl;
        for(int i=0; i<n; i++){
            int idx=queryIndices[i];
            char ch=queryCharacters[i];
           
            tree.update(0,0,slen-1, idx, ch);
            ans.push_back(tree.segment[0].best);
        }
        return ans;

        
    }
};