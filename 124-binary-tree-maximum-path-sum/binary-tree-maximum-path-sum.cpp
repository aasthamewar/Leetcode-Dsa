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
int sum;
    int helper(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int l = max(0,helper(root->left));
        int r = max(0,helper(root->right));
        int currsum = root->val+l+r;
        sum = max(currsum,sum); // update
        return root->val+max(l,r);
    }

    int maxPathSum(TreeNode* root){
        sum=INT_MIN;
        helper(root);
        return sum;
    }
};