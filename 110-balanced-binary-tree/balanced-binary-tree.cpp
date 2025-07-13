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
    // Helper function that returns height if balanced, else -1
    int check(TreeNode* root) {
        if (root == NULL) return 0;

        int lh = check(root->left);
        if (lh == -1) return -1;  // left subtree not balanced

        int rh = check(root->right);
        if (rh == -1) return -1;  // right subtree not balanced

        if (abs(lh - rh) > 1) return -1; // current node not balanced

        return 1 + max(lh, rh); // return height
    }

    bool isBalanced(TreeNode* root) {
        return check(root) != -1;
    }
};
