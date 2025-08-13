class Solution {
public:
    Node* connect(Node* root) {
        if (root == NULL) {
            return root;
        }

        queue<Node*> q;
        q.push(root);
        q.push(NULL);

        Node* prev = NULL;

        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();

            if (curr == NULL) {
                prev = NULL; // reset for new level
                if (!q.empty()) {
                    q.push(NULL);
                }
            } 
            else {
                if (curr->left != NULL) {
                    q.push(curr->left);
                }
                if (curr->right != NULL) {
                    q.push(curr->right);
                }

                if (prev != NULL) {
                    prev->next = curr;
                }

                prev = curr;
            }
        }
        return root;
    }
};
