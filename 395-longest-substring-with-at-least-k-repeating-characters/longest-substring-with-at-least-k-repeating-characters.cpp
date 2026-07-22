class Solution {
public:
    int longestSubstring(string s, int k) {

        int ans = 0;

        // Try every possible number of unique characters
        for (int targetUnique = 1; targetUnique <= 26; targetUnique++) {

            map<char, int> freq;

            int left = 0, right = 0;
            int unique = 0;
            int atleastK = 0;

            while (right < s.size()) {

                // Add current character
                if (freq[s[right]] == 0)
                    unique++;

                freq[s[right]]++;

                if (freq[s[right]] == k)
                    atleastK++;

                // Shrink window if unique characters exceed target
                while (unique > targetUnique) {

                    if (freq[s[left]] == k)
                        atleastK--;

                    freq[s[left]]--;

                    if (freq[s[left]] == 0) {
                        unique--;
                        freq.erase(s[left]);
                    }

                    left++;
                }

                if (unique == targetUnique && unique == atleastK)
                    ans = max(ans, right - left + 1);

                right++;
            }
        }

        return ans;
    }
};