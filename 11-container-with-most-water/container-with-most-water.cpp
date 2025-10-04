class Solution {
public:
    int maxArea(vector<int>& height) {
        int left=0;
        int right=height.size()-1;
        int maxiWater=0;
        while(left<right){
            int width=right-left;
            int effective_height=min(height[left],height[right]);
            int area=width*effective_height;

            //updating area
            maxiWater=max(maxiWater,area);

            //move pointer
            if(height[left]<height[right]){
                left++;
            }
            else{
                right--;
            }
        }
        return maxiWater;
    }
};