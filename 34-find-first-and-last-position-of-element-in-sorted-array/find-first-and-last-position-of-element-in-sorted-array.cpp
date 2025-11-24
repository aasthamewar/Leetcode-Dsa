class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int leftStart = 0, leftEnd = nums.size() - 1;
        int rightStart = 0, rightEnd = nums.size() - 1;
        int firstIndex = -1, lastIndex = -1;

        while (leftStart <= leftEnd || rightStart <= rightEnd) {
            int midLeft = leftStart + (leftEnd - leftStart) / 2;
            int midRight = rightStart + (rightEnd - rightStart) / 2;

            if (leftStart <= leftEnd && nums[midLeft] == target) {
                firstIndex = midLeft;
                leftEnd = midLeft - 1;
            } else if (rightStart <= rightEnd && nums[midRight] == target) {
                lastIndex = midRight;
                rightStart = midRight + 1;
            } else if ((leftStart <= leftEnd && nums[midLeft] < target) || 
                       (rightStart <= rightEnd && nums[midRight] < target)) {
                if (leftStart <= leftEnd && nums[midLeft] < target) leftStart = midLeft + 1;
                if (rightStart <= rightEnd && nums[midRight] < target) rightStart = midRight + 1;
            } else {
                if (leftStart <= leftEnd) leftEnd = midLeft - 1;
                if (rightStart <= rightEnd && nums[midRight] > target) rightEnd = midRight - 1;
            }
        }

        return {firstIndex, lastIndex};
    }
};