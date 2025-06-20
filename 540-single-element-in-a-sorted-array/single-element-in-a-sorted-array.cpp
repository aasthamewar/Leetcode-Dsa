class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        int l = 0, e = n - 1;

        while (l < e) {
            int mid = l + (e - l) / 2;

            // Ensure mid is even for comparison with mid + 1
            if (mid % 2 == 1) {
                mid--;
            }

            if (nums[mid] == nums[mid + 1]) {
                // Unique element is in the right half
                l = mid + 2;
            } else {
                // Unique element is in the left half (or at mid)
                e = mid;
            }
        }

        return nums[l];  // When l == e, we found the single element
    }
};
