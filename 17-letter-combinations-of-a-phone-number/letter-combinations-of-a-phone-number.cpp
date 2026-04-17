class Solution {
public:
    vector<string> ans;

    void solve(int index, string &digits, string &current, vector<string> &mapping){
        // base case
        if(index == digits.size()){
            ans.push_back(current);
            return;
        }

        // get letters for current digit
        string letters = mapping[digits[index] - '0'];

        // try each letter
        for(char ch : letters){
            current.push_back(ch);            // choose
            solve(index + 1, digits, current, mapping); // explore
            current.pop_back();               // backtrack (unchoose)
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) return {};

        vector<string> mapping = {
            "",     // 0
            "",     // 1
            "abc",  // 2
            "def",  // 3
            "ghi",  // 4
            "jkl",  // 5
            "mno",  // 6
            "pqrs", // 7
            "tuv",  // 8
            "wxyz"  // 9
        };

        string current = "";
        solve(0, digits, current, mapping);

        return ans;
    }
};