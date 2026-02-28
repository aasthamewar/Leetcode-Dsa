class Solution {
public:
    vector<int> minDistinctFreqPair(vector<int>& nums) {
        unordered_map<int,int> freq;
        for(int i=0;i<nums.size();i++){
            freq[nums[i]]++;
        }
        vector<int> a1;
        for(auto ele:freq){
            a1.push_back(ele.first);
        }
        sort(a1.begin(),a1.end());
        int d = a1.size();
        for (int i = 0; i < d; ++i) {
            int x = a1[i];
            for (int j = i + 1; j < d; ++j) {
                int y = a1[j];
                if (freq[x] != freq[y]) 
                    return {x, y};
            }
        }
        return {-1, -1};
    }
};