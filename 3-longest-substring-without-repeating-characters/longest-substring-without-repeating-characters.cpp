class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // unordered_set<char> seen;
        // int left = 0, right = 0, maxlen = 0;

        // while (right < s.size()) {
        //     // if character not seen we will expand the window
        //     if (seen.find(s[right]) == seen.end()) {
        //         seen.insert(s[right]);
        //         maxlen = max(maxlen, right - left + 1);
        //         right++;
        //     }
        //     // if duplicate found , we will shrink window from left
        //     else {
        //         seen.erase(s[left]);
        //         left++;
        //     }
        // }

        // return maxlen;
        unordered_set<char> seen;
        int right=0,left=0,maxlen=0;

        while(right<s.size()){
            //first we will check if the char r not duplicate
            if(seen.find(s[right])==seen.end()){
                seen.insert(s[right]);
                maxlen=max(maxlen,right-left+1);
                right++;
            }
            //if the char is duplicate for that
            else{
                seen.erase(s[left]);
                left++;
            }
        }
        return maxlen;
    }
};