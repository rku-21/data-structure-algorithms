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
    int maxiSum=INT_MIN;
    int solve(TreeNode* root){
          if(root==nullptr) return INT_MIN;

          int left=solve(root->left);
          int right=solve(root->right);

          if(left == INT_MIN && right == INT_MIN){
              maxiSum=max({maxiSum, root->val});
              return root->val;
          }
           if(left == INT_MIN){
              maxiSum=max({maxiSum, right, right+root->val,root->val});
              return max(root->val, right+root->val);
          }
           if( right == INT_MIN){
            maxiSum=max({maxiSum , left , left+root->val, root->val});
            return max(root->val, left+root->val);
          }
          else {
              maxiSum=max({maxiSum, left, right , left+right+root->val, root->val, left+root->val, right+root->val});
              return max({root->val, left+root->val, right+root->val});
          }
          


         
          return max(left,right)+root->val;
    }
    int maxPathSum(TreeNode* root) {
        solve(root);
        return maxiSum;
        
    }
};