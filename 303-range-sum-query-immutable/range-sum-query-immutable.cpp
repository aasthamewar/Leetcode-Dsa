class NumArray {
public:vector<int>nums;
vector<int>pref;
    NumArray(vector<int>& nums) {
        this->nums=nums;
        int n=nums.size();
        pref.resize(n);
        prefcalculate(nums);
    }
    
    int sumRange(int left, int right) {
        if(left==0){
            return pref[right];
        }
        return pref[right]-pref[left-1];
    }
    void prefcalculate(vector<int>& nums){
        pref[0]=nums[0];
        for(int i=1;i<nums.size();i++){
        pref[i]=nums[i]+pref[i-1];
        }

    }
    
};
