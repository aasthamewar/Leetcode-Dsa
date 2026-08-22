class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        vector<int>values(26);
        for(int i=0;i<26;i++){
            values[i]=i+1;
        }
        //custom values updated
        for(int i=0;i<chars.size();i++){
            values[chars[i]-'a'] = vals[i];
        }
        // subarray wala concept
        int current=0;
        int ans=0;
        for(int i=0;i<s.size();i++){
            current+=values[s[i]-'a'];
            current=max(0,current);
            ans=max(current,ans);
        }
        return ans;
    }
};