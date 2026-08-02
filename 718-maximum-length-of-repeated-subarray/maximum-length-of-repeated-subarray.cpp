class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        // ********* Brute force solution *********
        // int ans = 0;
        // for (int i = 0; i < nums1.size(); i++) {
        //     int len = 0;
        //     for (int j = 0; j < nums2.size(); j++) {
        //         while (i + len < nums1.size() && j + len < nums2.size() &&
        //                nums1[i + len] == nums2[j + len]) {
        //             len++;
        //         }
        //         ans = max(ans, len);
        //     }
            
        // }
        // return ans;

         vector<vector<int>> dp(nums1.size() + 1,
                               vector<int>(nums2.size() + 1, 0));
        int maxi=0;
        for(int i=1;i<=nums1.size();i++){
            for(int j=1;j<=nums2.size();j++){
                if(nums1[i-1]==nums2[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;
                }
                maxi=max(maxi,dp[i][j]);
            }
        }
        return maxi;

    }
};