class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        string repeated = a;
    int count = 1;

    // Keep repeating 'a' until length is >= length of 'b'
    while (repeated.length() < b.length()) {
        repeated += a;
        count++;
    }

    // Check if 'b' is now a substring
    if (repeated.find(b) != string::npos) {
        return count;
    }

    // Try one more repetition to cover overlapping case
    repeated += a;
    count++;

    if (repeated.find(b) != string::npos) {
        return count;
    }

    return -1;
    }
};