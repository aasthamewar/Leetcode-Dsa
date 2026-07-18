class Solution {
public:
    string rearrangeString(string s, char x, char y) {
        string other="";
        string y_chr="";
        string x_chr="";

        for(char c:s){
            if(c==y){
                y_chr+=c;
            }
            else if(c==x){
                x_chr+=c;
            }
            else{
                other+=c;
            }
        }
        return other+y_chr+x_chr;
    }
};