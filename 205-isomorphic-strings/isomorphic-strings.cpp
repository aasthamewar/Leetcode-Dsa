class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,int>s1;
        unordered_map<char,int>s2;
        for(int i=0;i<s.size();i++){
            if(s1.find(s[i])==s1.end()){
                s1[s[i]]=i;
            }
            if(s2.find(t[i])==s2.end()){
                s2[t[i]]=i;
            }
            if(s1[s[i]]!=s2[t[i]]){
                return false;
            }
        }
        return true;
    }
};