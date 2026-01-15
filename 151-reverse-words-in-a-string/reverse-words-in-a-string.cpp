class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        string ans="";

        // first reverse the whole s
        reverse(s.begin(),s.end());
        for(int i=0;i<n;i++){
            // stores words by words
            string word = "";
            while(i<n && s[i]!=' '){
                word+=s[i];
                i++;
            }
            // after storing reverse the word
            reverse(word.begin(),word.end());

            // check if length of word is greater than 0
            if(word.size()>0){
                ans+=" "+word;
            }
        }
        return ans.substr(1);
    }
};