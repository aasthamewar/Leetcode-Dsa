class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxiwater=0;
        int start=0,end=height.size()-1;
        while(start<end){
            int width=end-start;
            int effective_height=min(height[start],height[end]);
            int area=width*effective_height;

            // update the area
            maxiwater=max(maxiwater,area);

            // move the pointer
            if(height[start]<height[end]){
                start++;
            }
            else{
                end--;
            }
        }
        return maxiwater;
    }
};