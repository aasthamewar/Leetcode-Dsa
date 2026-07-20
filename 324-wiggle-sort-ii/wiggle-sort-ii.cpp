class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int>left;
        int mid=(n+1)/2;
        for(int i=0;i<mid;i++){
            left.push_back(nums[i]);
        }
        vector<int>right;
        for(int i=mid;i<n;i++){
            right.push_back(nums[i]);
        }
        int i = left.size() - 1;
        int j = right.size() - 1;
        int idx = 0;

        while (i >= 0 || j >= 0) {

            if (i >= 0)
                nums[idx++] = left[i--];

            if (j >= 0)
                nums[idx++] = right[j--];
        }
        
    }
};