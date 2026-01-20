class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //brute force approach
        int maxi=0;
        
        for(int i=0;i<s.size();i++){
            unordered_set<char> st;
            for(int j=i;j<s.size();j++){
                if(st.count(s[j])) // duplicate finding
                {
                    break;
                }
                st.insert(s[j]);
                maxi=max(maxi,j-i+1);
            }
        }
        return maxi;
    }
};