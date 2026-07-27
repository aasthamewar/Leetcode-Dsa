class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int cnt=0;
        
        int left=0,seq=0,ans=0;
        for(int i=2;i<nums.size();i++){
            if((nums[i]-nums[i-1]) == (nums[i-1]-nums[i-2])){
                seq++;
                ans+=seq;
            }
            else{
                seq=0;
            }

        }
        
        return ans;
    }
};