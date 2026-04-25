class Solution {
public:
    int compareBitonicSums(vector<int>& nums) {
        int n = nums.size();

        int peak = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] > nums[peak]){
                peak = i;
            }
        }

        long long sum1 = 0, sum2 = 0;

        for(int i = 0; i <= peak; i++){
            sum1 += nums[i];
        }

        for(int i = peak; i < n; i++){
            sum2 += nums[i];
        }

        if(sum1 > sum2) return 0;
        else if(sum2 > sum1) return 1;
        else return -1;
    }
};