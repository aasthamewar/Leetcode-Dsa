class Solution {
public:
    double myPow(double x, long long int n) {
        if(n==0)return 1.00;

        //if negative n
        if(n<0){
            x = 1/x;
            n = -n;
        }
        double ans = 1.00;
        while(n>0){
            if(n%2==1){
                ans = ans*x;
            }
            x = x*x;
            n /= 2;
        }
        return ans;
    }
};