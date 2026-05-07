class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // [3,2,3]
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        vector<int>majorityel;
        int maxcnt=nums.size()/3; //3/3=1
        for(auto x:mp){
            int element=x.first; // 2,3,3
            int cnt=x.second; // 2-1, 3-2
            if(cnt>maxcnt){
                majorityel.push_back(element);
            }
        }
        return majorityel;
    }
};