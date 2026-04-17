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
int solve(TreeNode* root,int maxi){
    int cnt=0;
    if(!root)return 0;
    if(root->val>=maxi)cnt=1;
    maxi=max(maxi,root->val);
    cnt+=solve(root->left,maxi);
    cnt+=solve(root->right,maxi);

    return cnt;
}
    int goodNodes(TreeNode* root) {
        return solve(root,root->val);
    }
};