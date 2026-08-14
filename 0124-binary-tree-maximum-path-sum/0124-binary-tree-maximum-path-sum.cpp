/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
   int inf=INT_MIN;
   pair<int,int> solve(TreeNode* root){
       if(root==nullptr) return {inf,0};

       auto l = solve(root->left);
       auto r=solve(root->right);

       int leftbest=l.first;
       int rightbest=r.first;
       int left=l.second;
       int right=r.second;
       pair<int,int>ans;
       ans.first=max({leftbest,rightbest, left+root->val , right+root->val, root->val,left+right+root->val});
       ans.second=max({left+root->val, right+root->val, root->val});

       return ans;


   }
    int maxPathSum(TreeNode* root) {

        return solve(root).first;
        
    }
};