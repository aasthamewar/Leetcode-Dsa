class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> count(26, 0);
    int left = 0, maxCount = 0, maxLen = 0;

    for (int right = 0; right < s.size(); right++) {
        count[s[right] - 'A']++;
        maxCount = max(maxCount, count[s[right] - 'A']);

        // If the current window needs more than k changes, shrink it
        while ((right - left + 1) - maxCount > k) {
            count[s[left] - 'A']--;
            left++;
        }

        maxLen = max(maxLen, right - left + 1);
    }

    return maxLen;
    }
};