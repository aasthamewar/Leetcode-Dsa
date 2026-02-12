class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();
        int ans = 0;
        for(int i=0;i<s.size();i++){
            unordered_map<char,int> freq;
            for(int j=i;j<n;j++){
                freq[s[j]]++;

                int mini = INT_MAX, maxi=INT_MIN;
                for(auto &p:freq){
                    mini = min(mini,p.second);
                    maxi = max(maxi,p.second);
                }
                if(mini == maxi){
                    ans = max(ans,j-i+1);
                }
            }
        }
        return ans;
    }
};