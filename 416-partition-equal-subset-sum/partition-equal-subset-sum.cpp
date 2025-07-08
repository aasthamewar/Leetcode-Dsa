class Solution {
public:
bool isSubset(vector<int>& nums,int n,int sum,vector<vector<int>>& dp){
    if(n==0)return false;
    if(sum==0)return true;
    if(dp[n][sum]!=-1)return dp[n][sum];
    if(nums[n-1]>sum)return dp[n][sum] = isSubset(nums,n-1,sum,dp);
    return dp[n][sum] = isSubset(nums,n-1,sum,dp)|| isSubset(nums,n-1,sum-nums[n-1],dp);

}
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(sum%2!=0){
            return false;
        }
        sum/=2;
        vector<vector<int>> dp(n+1,vector<int>( sum+1,-1));
        return isSubset(nums,n,sum,dp);

    }
};