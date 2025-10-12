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
    int moves = 0;
    int solve(TreeNode* root){
        if(!root)return 0;
        //take abs value of left and right when u call to the fun why cause to prevernt from the -ve value
        int l = solve(root->left);
        int r = solve(root->right);
        moves += abs(l) + abs(r);
        return (l + r + root->val) - 1; 
    }
    int distributeCoins(TreeNode* root) {
        solve(root);
        return moves;
    }
};