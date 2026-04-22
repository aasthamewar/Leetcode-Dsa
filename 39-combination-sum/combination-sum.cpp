class Solution {
public:
void solve(int index,vector<int>& candidates,int target, vector<int>& temp,vector<vector<int>>&ans){
    if(target==0){
        ans.push_back(temp);
        return;
    }

    if(index == candidates.size() || target < 0){
            return;
    }
    //take case;
    temp.push_back(candidates[index]);
    solve(index,candidates,target-candidates[index],temp,ans);
    temp.pop_back();

    //not take case
    solve(index+1,candidates,target,temp,ans);
}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>temp;
        vector<vector<int>>ans;
        solve(0,candidates,target,temp,ans);
        return ans;
    }
};