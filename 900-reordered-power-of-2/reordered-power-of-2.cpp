class Solution {
public:
string sorted(int n){
    string s=to_string(n);
    sort(s.begin(),s.end());
    return s;
}
    bool reorderedPowerOf2(int n) {
        if(n==1)return true;
        string x = sorted(n);
        for(int i=1;i<=30;i++){
            int power=1<<i;
            if(x==sorted(power)){
                return true;
            }
        }
        return false;
    }
};