class Solution {
public:
    bool validDigit(int n, int x) {
        string s=to_string(n);
        char ch=x+'0';
        for(int i=1;i<s.size();i++){
            if(s[0]!=ch && s[i]==ch){
                return true;
            }
        }
        return false;
    }
};