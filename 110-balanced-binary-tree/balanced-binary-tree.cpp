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
    int solve(TreeNode* root){
        if(root == nullptr)return true; 
        int left = solve(root->left);
        int right = solve(root->right);
        
       
        return max(left, right) + 1;
    }
    bool isBalanced(TreeNode* root) {
                if(root == nullptr)return true; 

        int leftHeight = solve(root->left);
        int rightHeight = solve(root->right);
        if(abs(leftHeight - rightHeight) > 1)return false;
        if (isBalanced(root->left) && isBalanced(root->right)) {
            return true;
        } else {
            return false;
        }
    }
};
