class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n=nums.size();
        int start=0,end=n-1;
        while(start<=end){
            int mid = start + (end-start)/2;
            if(nums[mid]==target){
                return true;
                
            }
            //handling duplicated
            if(nums[mid]==nums[start]&& nums[mid]==nums[end]){
                start++;
                end--;
                continue;
            }

            //left part sorted hai agar
            else if(nums[start]<=nums[mid]){
                if(nums[start]<=target && target<nums[mid]){
                    end=mid-1;
                }
                else{
                    start=mid+1;
                }
            }
            //right half
            else{
                if(nums[mid]<target && target<=nums[end]){
                    start=mid+1;
                }
                else{
                    end=mid-1;
                }
            }
        }
        return false;
    }
};