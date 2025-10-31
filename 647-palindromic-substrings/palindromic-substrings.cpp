class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int count = 0;

        // For every possible center
        for (int center = 0; center < 2 * n - 1; center++) {
            int left = center / 2;
            int right = left + center % 2;

            // Expand around center
            while (left >= 0 && right < n && s[left] == s[right]) {
                count++;
                left--;
                right++;
            }
        }

        return count;
    }
};