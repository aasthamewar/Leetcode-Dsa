class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n=nums.size(), incre=1,previncre=0,maxlen=0;
        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1]){
                incre++;

            }
            else{
                previncre = incre;
                incre=1;
            }
            maxlen = max(maxlen,max(incre >> 1, min(previncre,incre)));
            if(maxlen >= k) return true;


        }
        return false;        

    }
};