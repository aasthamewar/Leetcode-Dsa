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
vector<int> result;
    vector<int> inorderTraversal(TreeNode* root) {
        if(root==nullptr){
            return result;
        }
        inorderTraversal(root->left);
        result.push_back(root->val);
        inorderTraversal(root->right);
        return result;
    }
};