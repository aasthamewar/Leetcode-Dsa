class Solution {
public:
    int maxProduct(vector<int>& nums) {
        //brute force
        
        // int ans=nums[0];
        // for(int i=0;i<nums.size();i++){
        //     int prod=1;
        //     for(int j=i;j<nums.size();j++){
        //         prod*=nums[j];
        //         ans=max(ans,prod);
        //     }
        // }
        // return ans;

        int maxi = INT_MIN;
        int prod = 1;

        for(int i=0;i<nums.size();i++){
            prod*=nums[i];
            maxi=max(maxi,prod);
            if(prod == 0){
                prod = 1;
            }
        }
        prod = 1;
        for(int j=nums.size()-1;j>=0;j--){
            prod*=nums[j];
            maxi=max(maxi,prod);
            if(prod == 0){
                prod = 1;
            }
        }
        return maxi;
    }
};