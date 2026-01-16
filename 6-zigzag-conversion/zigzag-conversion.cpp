class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> rows(numRows);
        // Edge case: zigzag not possible
        if (numRows == 1 || numRows >= s.size())
            return s;
        int currentrow = 0;
        int direction = 1; //+1->down, -1->up
        for (int i = 0; i < s.size(); i++) {
            rows[currentrow].push_back(s[i]);

            // change direction at boundaries
            if (currentrow == 0) {
                direction = 1;
            } else if (currentrow == numRows - 1) {
                direction = -1;
            }

            currentrow += direction;
        }
        string result;
        for (int i = 0; i < numRows; i++) {
            result += rows[i];
        }
        return result;
    }
};