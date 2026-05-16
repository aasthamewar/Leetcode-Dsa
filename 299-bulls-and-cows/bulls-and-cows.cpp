class Solution {
public:
    string getHint(string secret, string guess) {
        vector<int>secretmp(10,0);
        vector<int>guessmp(10,0);
        int bull=0,cows=0;
        for(int i=0;i<secret.size();i++){
            int x=secret[i]-'0';
            int y=guess[i]-'0';
            if(x==y){
                bull++;
            }
            else{
                secretmp[x]++;
                guessmp[y]++;
            }
        }
        for(int i=0;i<10;i++){
            cows+=min(secretmp[i],guessmp[i]);
        }
        return to_string(bull) + "A" + to_string(cows) + "B";

    }
};