class Solution {
public:
    int myAtoi(string s) {
        int i=0,sign=1,result=0;
        if(s.size()==0)return 0;

        //whitespace
        while(i<s.size() && s[i]==' ')i++;

        //sign check
        if(i<s.size() && (s[i]=='+' || s[i]=='-')){
           sign=(s[i]=='-')?-1:1;
           i++;
        }
        //string converting into integer
        while(i<s.size() && isdigit(s[i])){
            int digit=s[i]-'0';
            //overflow condition checking
            if(result > (INT_MAX-digit)/10){
                return (sign==1)?INT_MAX : INT_MIN;
            }
            result=result*10+digit;
            i++;
        }
        return result * sign;

    }
};