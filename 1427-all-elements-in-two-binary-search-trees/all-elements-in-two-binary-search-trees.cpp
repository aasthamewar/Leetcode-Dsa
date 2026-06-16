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
void inorder(TreeNode* root1,vector<int>& arr){
    if(root1==NULL)return;
    inorder(root1->left,arr);
    arr.push_back(root1->val);
    inorder(root1->right,arr);
}
void inorder1(TreeNode* root2, vector<int>& arr){
    if(root2==NULL)return;
    inorder(root2->left,arr);
    arr.push_back(root2->val);
    inorder(root2->right,arr);
}
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int>arr;
        inorder(root1,arr);
        inorder1(root2,arr);
        sort(arr.begin(),arr.end());
        return arr;

    }
};