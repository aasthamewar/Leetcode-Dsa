class Solution {
public:
    vector<int> findAnagrams(string s, string p) {

        vector<int> ans;

        if (s.size() < p.size())
            return ans;

        vector<int> freqP(26, 0);
        vector<int> freqS(26, 0);

        // Frequency of pattern
        for (char ch : p)
            freqP[ch - 'a']++;

        int k = p.size();

        // First window
        for (int i = 0; i < k; i++)
            freqS[s[i] - 'a']++;

        if (freqS == freqP)
            ans.push_back(0);

        // Sliding window
        for (int i = k; i < s.size(); i++) {

            // Remove left character
            freqS[s[i - k] - 'a']--;

            // Add current character
            freqS[s[i] - 'a']++;

            if (freqS == freqP)
                ans.push_back(i - k + 1);
        }

        return ans;
    }
};