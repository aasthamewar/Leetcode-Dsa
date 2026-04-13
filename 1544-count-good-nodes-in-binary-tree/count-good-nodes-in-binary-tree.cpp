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
    int solve(TreeNode* root, int mx) {
        if (!root) return 0;

        int cnt = 0;
        if (root->val >= mx) cnt = 1;

        mx = max(mx, root->val);

        cnt += solve(root->left, mx);
        cnt += solve(root->right, mx);

        return cnt;
    }

    int goodNodes(TreeNode* root) {
        return solve(root, root->val);
    }
};