class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int pref = 0;
        unordered_map<int, int> mp;
        mp[0] = 1;
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            pref += nums[i];
            if (mp.count(pref - k)) {
                cnt += mp[pref - k];
            }

            mp[pref]++;
        }
        return cnt;
    }
};