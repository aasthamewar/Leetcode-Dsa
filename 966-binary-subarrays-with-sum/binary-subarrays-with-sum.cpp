class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int>mp;
        mp[0] = 1;
        int res=0;
        int currsum=0;
        for(int i=0;i<nums.size();i++){
            currsum += nums[i];
            int remaining = currsum - goal;
            if(mp.find(remaining) != mp.end()){
                res+=mp[remaining];
            } 
            //updating in map
            mp[currsum]++;
        }
        return res;
    }
};