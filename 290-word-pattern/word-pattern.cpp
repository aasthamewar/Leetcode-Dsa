class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;
        stringstream ss(s);
        int countwords=0;
        string token;

        while(getline(ss,token,' ')){
            words.push_back(token);
            countwords++;
        }
        int n=pattern.size();
        unordered_map<string,char> mp;
        set<char>used;
        if(n!=countwords){
            return false;
        }
        for(int i=0;i<n;i++){
            string word=words[i];
            char ch=pattern[i];
            if(mp.find(word)==mp.end() && used.find(ch)==used.end()){
                used.insert(ch);
                mp[word]=ch;
            }
            else if(mp[word]!=ch){
                return false;
            }
        }
        return true;
    }
};