class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> ans;
        for(int i=0;i<nums.size();i++){
            int x=nums[i];
            int y=target-x;
            if(ans.find(y)!=ans.end()){
                return {ans[y],i};
            }
            ans[x]=i;
        }
        return {-1,-1};
    }
};