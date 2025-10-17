class Solution {
public:
    int sum = 0; // running sum of visited nodes

    void reverseInorder(TreeNode* root) {
        if (!root) return;

        // Step 1: visit right subtree (greater nodes)
        reverseInorder(root->right);

        // Step 2: update node value
        sum += root->val;    // add original node value to running sum
        root->val = sum;     // update node

        // Step 3: visit left subtree
        reverseInorder(root->left);
    }

    TreeNode* convertBST(TreeNode* root) {
        sum = 0;
        reverseInorder(root);
        return root;
    }
};
