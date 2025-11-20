class Solution {
public:
    struct Node {
        Node* bit[2] = {NULL, NULL};
    };

    Node* root = new Node();

    void insert(int num) {
        Node* cur = root;
        for (int i = 31; i >= 0; i--) {
            int b = (num >> i) & 1;
            if (!cur->bit[b]) {
                cur->bit[b] = new Node();
            }
            cur = cur->bit[b];
        }
    }

    int getMax(int num) {
        Node* cur = root;
        int ans = 0;

        for (int i = 31; i >= 0; i--) {
            int b = (num >> i) & 1;
            int opposite = 1 - b;

            // if opposite bit exists, take it to maximize XOR
            if (cur->bit[opposite]) {
                ans |= (1 << i);
                cur = cur->bit[opposite];
            } else {
                cur = cur->bit[b];
            }
        }

        return ans;
    }

    int findMaximumXOR(vector<int>& nums) {
        for (int x : nums) insert(x);

        int maxi = 0;
        for (int x : nums) {
            maxi = max(maxi, getMax(x));
        }

        return maxi;
    }
};
