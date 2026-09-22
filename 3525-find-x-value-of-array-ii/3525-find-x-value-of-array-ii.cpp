struct Node {
    int count[5]={0};
    int r; // remainder
};

class Tree {
    public : 
    int k;
    int n;
    vector<Node>segTree;

    Tree(auto&nums, int k ,int n){
        this->n=n;
        this->k=k;

        segTree.resize(4*n, Node());

        buildTree(0, 0, n-1, nums);
    }
    Node mergeNodes(Node & left , Node & right){
        Node result;
        result.r=(left.r * right.r) %k;

        for(int x=0; x<5; x++){
            result.count[x]=left.count[x];
        }

        for(int x=0; x<5; x++){
            int new_r=(left.r * x)%k;
            result.count[new_r]+=right.count[x];
        }

        return result;


    }
    void buildTree(int i ,int l, int r, auto&nums){
        if(l==r){
            makeLeaf(i, nums[l]);
            return;
        }
        int mid=(l+r)/2;
        buildTree(2*i+1, l, mid, nums);
        buildTree(2*i+2, mid+1, r, nums);

        segTree[i]=mergeNodes(segTree[2*i+1], segTree[2*i+2]);
    }

    void makeLeaf(int i , int val){
        segTree[i].r=val%k;
        
        for(int x=0; x<5; x++){
            segTree[i].count[x]=0;
        }
        segTree[i].count[val%k]=1;

    }
    void treeUpdate(int i, int l, int r, int idx ,int val){
        if(l==r){
            makeLeaf(i, val);
            return;
        }
        int mid=(l+r)/2;
        if(idx <=mid){
            treeUpdate(2*i+1, l, mid, idx, val);
        }
        else treeUpdate(2*i+2, mid+1, r, idx , val);

        segTree[i]=mergeNodes(segTree[2*i+1], segTree[2*i+2]);
    }
    void update(int idx, int val){
        treeUpdate(0, 0, n-1, idx, val);
    }
    Node treeQuery(int i ,int l, int r, int start,int end){
        if(l>=start && r<=end){
            return segTree[i];
        }

        int mid=(l+r)/2;

        if(end <=mid){
            return treeQuery(2*i+1, l, mid ,start, end);
        }
        else if(start > mid){
            return treeQuery(2*i+2, mid+1, r, start, end);
        }

        Node left=treeQuery(2*i+1, l, mid, start, end);
        Node right=treeQuery(2*i+2, mid+1, r, start, end);
 
     return mergeNodes(left, right);
    }
    Node query(int start){
        return treeQuery(0, 0, n-1, start,n-1);
    }




};

class Solution {
public:
    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
        int n=nums.size();

        Tree tree(nums, k, n);

        vector<int>ans;

        for(auto q:queries){

            int idx=q[0];
            int val=q[1];
            int start=q[2];
            int x=q[3];

            tree.update(idx, val);
            Node tempNode=tree.query(start);
            ans.push_back(tempNode.count[x]);
        }

        return ans;

        
    }
};