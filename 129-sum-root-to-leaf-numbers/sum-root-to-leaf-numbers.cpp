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

void solve(TreeNode* root,int curr){
    if(root==NULL)return;
    curr=curr*10+root->val;
    if(root->left==NULL && root->right==NULL){
        ans+=curr;
        return;
    }
    else{
        solve(root->left,curr);
        solve(root->right,curr);
    }

}
    int sumNumbers(TreeNode* root) {
        int curr=0;
        solve(root,curr);
        return ans;
    }
};