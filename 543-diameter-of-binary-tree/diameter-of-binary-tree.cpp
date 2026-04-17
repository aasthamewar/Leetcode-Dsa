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
int ans=0;
int diameter(TreeNode* root){
    if(!root)return 0;
    int l=diameter(root->left);//2
    int r=diameter(root->right);//1
    ans=max(ans,l+r);//(0,3)
    return 1+max(l,r);//1+2=3
}
    int diameterOfBinaryTree(TreeNode* root) {
        diameter(root);
        return ans;
    }
};