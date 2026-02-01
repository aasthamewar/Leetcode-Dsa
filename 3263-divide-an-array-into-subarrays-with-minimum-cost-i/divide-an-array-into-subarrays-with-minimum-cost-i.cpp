class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n = nums.size();
        //edge case
        if(n==3){
            return nums[0]+nums[1]+nums[2];
        }
        // As the first element is fixed nums[0], have to find other two element which is smaller.
        int mini1=100;
        int mini2=100;

        for(int i=1;i<n;i++){
            if(nums[i]<mini1){
                mini2=mini1;
                mini1=nums[i];
            }
            else if(nums[i]<mini2){
                mini2=nums[i];
            }
            
        }
        return nums[0]+mini1+mini2;
        


    }
};