class Solution {
public:
    string sortVowels(string s) {
        unordered_map<char,int>mp;
        unordered_map<char,int>firpos;
        string vowelsonly="";
        string vowels="aeiou";
        for(int i=0;i<s.size();i++){
            if(vowels.find(s[i])!=string::npos){
                if(mp[s[i]]==0){
                    firpos[s[i]]=i;
                }
                mp[s[i]]++;
                vowelsonly+=s[i];
            }
        }
        sort(vowelsonly.begin(),vowelsonly.end(), [&](char a,char b){
            if(mp[a]!=mp[b]){
                return mp[a]>mp[b];
            }
            return firpos[a]<firpos[b];
        });
        int idx=0;
        for(int i=0;i<s.size();i++){
            if(vowels.find(s[i])!=string::npos){
                s[i]=vowelsonly[idx++];
            }
        }
        return s;
        
    }
};