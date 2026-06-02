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
bool mirror(TreeNode* Left, TreeNode* Right){
    if(!Left && !Right)return true;
    if(!Left || !Right)return false;
    if(Left->val!=Right->val)return false;
    return mirror(Left->left, Right->right) && mirror(Left->right, Right->left);
}
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)return true;
        return mirror(root->left, root->right); 
    }
};