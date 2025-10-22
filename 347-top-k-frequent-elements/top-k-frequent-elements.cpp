class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        for (int n : nums) freq[n]++;

        int nSize = nums.size();
        vector<vector<int>> bucket(nSize + 1);

        for (auto& [num, count] : freq)
            bucket[count].push_back(num);

        vector<int> result;
        for (int i = nSize; i >= 0 && result.size() < k; --i) {
            for (int num : bucket[i]) {
                result.push_back(num);
                if (result.size() == k) break;
            }
        }
        return result;
    }
};
