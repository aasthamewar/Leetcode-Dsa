class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();

        if (n1 > n2) return false;

        vector<int> s1cnt(26, 0);
        vector<int> s2cnt(26, 0);

        for(int i = 0; i < n1; i++) {
            s1cnt[s1[i] - 'a']++;
            s2cnt[s2[i] - 'a']++;
        }

        
        for(int i = 0; i < n2 - n1; i++) {
            if (s1cnt == s2cnt) return true;

            s2cnt[s2[i] - 'a']--;
            s2cnt[s2[i + n1] - 'a']++;
        }

        return s1cnt == s2cnt;
    }
};