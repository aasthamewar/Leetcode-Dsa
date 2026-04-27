class Solution {
public:
    string multiply(string nums1, string nums2) {
        if(nums1[0] == '0' || nums2[0] == '0'){
            return "0";
        }
        vector<int>ans(nums1.size()+nums2.size(),0);
        for(int i=nums2.size()-1;i>=0;i--){
            for(int j=nums1.size()-1;j>=0;j--){
                ans[i+j+1]+=(nums2[i]-'0')*(nums1[j]-'0');
                ans[i+j]+=ans[i+j+1]/10;
                ans[i+j+1]%=10;
            }
        }
        int i=0;
        while(ans[i]==0){
            i++;
        }
        string result="";
        while(i<ans.size()){
            result.push_back(ans[i]+'0');
            i++;
        }
        return result;
    }
};