class Solution {
public:
    int countElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int countQualified = 0;

        for (int i = 0; i < n; i++) {
            // first index with value > nums[i]
            int idx = upper_bound(nums.begin(), nums.end(), nums[i]) - nums.begin();
            int greaterCount = n - idx;

            if (greaterCount >= k) {
                countQualified++;
            }
        }

        return countQualified;
    }
};
