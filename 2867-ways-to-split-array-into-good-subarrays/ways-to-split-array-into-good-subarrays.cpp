class Solution {
public:
    const int MOD = 1e9 + 7;

    int numberOfGoodSubarraySplits(vector<int>& nums) {
        long long ans = 1;
        int prevOne = -1;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                if (prevOne != -1) {
                    // Number of possible split positions
                    ans = (ans * (i - prevOne)) % MOD;
                }
                prevOne = i;
            }
        }

        // No 1 present
        if (prevOne == -1)
            return 0;

        return ans;
    }
};