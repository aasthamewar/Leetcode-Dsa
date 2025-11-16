class Solution {
public:
    int maximizeExpressionOfThree(vector<int>& nums) {
        int maxi1 = INT_MIN, maxi2 = INT_MIN, mini1 = INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>maxi1){
                maxi2=maxi1;
                maxi1=nums[i];
            }
            else if(nums[i]>maxi2){
                maxi2=nums[i];
            }

            // update min1
            if (nums[i] < mini1) {
                mini1 = nums[i];
            }
        }
        return maxi1+maxi2-mini1;
    }
};