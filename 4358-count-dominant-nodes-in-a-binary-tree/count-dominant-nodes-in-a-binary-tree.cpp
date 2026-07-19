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
    int cnt = 0;
    int dfs(TreeNode* root) {
        if(!root)return INT_MIN;
        int leftnode = dfs(root->left);
        int rightnode = dfs(root->right);

        int maxi = max(root->val, max(leftnode, rightnode));
        if (root->val == maxi) {
            cnt++;
        }
        return maxi;
    }
    int countDominantNodes(TreeNode* root) {
        dfs(root);

        return cnt;
    }
};