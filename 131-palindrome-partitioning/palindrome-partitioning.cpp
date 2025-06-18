class Solution {
public:
    bool isPalin(string s){
       string s2=s;
       reverse(s2.begin(),s2.end());

       return s==s2;
    }
    void getPalin(string s, vector<string>& partition,
                  vector<vector<string>>& ans) {
        // base case
        if (s.size() == 0) {
            ans.push_back(partition);
            return;
        }

        for (int i = 0; i < s.size(); i++) {
            string part = s.substr(0, i + 1);
            if (isPalin(part)) {
                partition.push_back(part);
                getPalin(s.substr(i + 1), partition, ans);
                partition.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<string> partition;
        vector<vector<string>> ans;

        getPalin(s,partition,ans);
        return ans;
   }
};