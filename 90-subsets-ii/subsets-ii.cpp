class Solution {
private:
    void solve(int index, vector<int>& nums, vector<int>& curr, vector<vector<int>>& ans) {
        ans.push_back(curr); // add current subset
        
        for (int i = index; i < nums.size(); i++) {
            // skip duplicates at same recursion depth
            if (i > index && nums[i] == nums[i - 1]) continue;
            
            curr.push_back(nums[i]);
            solve(i + 1, nums, curr, ans);
            curr.pop_back(); // backtrack
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        sort(nums.begin(), nums.end()); // sort to group duplicates
        solve(0, nums, curr, ans);
        return ans;
    }
};
