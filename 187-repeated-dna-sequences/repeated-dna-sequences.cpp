class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {

        map<string, int> mp;
        vector<string> res;
        for (int i = 0; i + 9 < s.size(); i++) {
            string temp = s.substr(i, 10);

            mp[temp]++;

            if (mp[temp] == 2)
                res.push_back(temp);
        }

        return res;
    }
};