/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int ans = 0;

    int solve(TreeNode* root) {

        if (root == NULL)
            return 0;

        int left = solve(root->left);
        int right = solve(root->right);

        int leftarrow = 0;
        int rightarrow = 0;

        if (root->left && root->left->val == root->val) {
            leftarrow = left + 1;
        }

        if (root->right && root->right->val == root->val) {
            rightarrow = right + 1;
        }

        ans = max(ans, leftarrow + rightarrow);

        return max(leftarrow, rightarrow);
    }

    int longestUnivaluePath(TreeNode* root) {

        solve(root);

        return ans;
    }
};