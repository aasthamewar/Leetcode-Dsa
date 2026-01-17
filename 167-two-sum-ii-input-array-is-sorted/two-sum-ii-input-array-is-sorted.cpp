class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int>indexes(2);
        int start=0,end=numbers.size()-1;
        while(start<=end){
            //int mid=start+(end-start)/2;
            int sum=numbers[start]+numbers[end];
            if(sum==target){
                return {start+1,end+1};
            }
            else if(sum>target){
                end--;
            }
            else{
                start++;
            }

        }
        return {-1,1};
    }
};