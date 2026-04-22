class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n == 0) return 0;

        int total = 0;
        vector<int> leftmost(n), rightmost(n);

        // Initialize
        leftmost[0] = height[0];
        for(int i = 1; i < n; i++){
            leftmost[i] = max(leftmost[i-1], height[i]);
        }

        rightmost[n-1] = height[n-1];
        for(int i = n-2; i >= 0; i--){
            rightmost[i] = max(rightmost[i+1], height[i]);
        }

        for(int i = 0; i < n; i++){
            total += min(leftmost[i], rightmost[i]) - height[i];
        }

        return total;
    }
};