class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> nodes; // x -> y -> multiset of node values
        queue<pair<TreeNode*, pair<int, int>>> todo; // node, x, y
        todo.push({root, {0, 0}});

        while (!todo.empty()) {
            auto a = todo.front();
            todo.pop();
            TreeNode* node = a.first;
            int x = a.second.first;
            int y = a.second.second;

            nodes[x][y].insert(node->val);

            // Traverse left and right children
            if (node->left) {
                todo.push({node->left, {x - 1, y + 1}});
            }
            if (node->right) {
                todo.push({node->right, {x + 1, y + 1}});
            }
        }

        vector<vector<int>> result;
        for (auto& p : nodes) {
            vector<int> col;
            for (auto& q : p.second) {
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            result.push_back(col);
        }

        return result;
    }
};
