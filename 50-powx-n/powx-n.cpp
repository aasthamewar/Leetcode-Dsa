class Solution {
public:
    double myPow(double x, long long n) {
        if (n == 0) return 1.0;

        // Handle negative exponent
        if (n < 0) {
            x = 1 / x;
            n = -n;
        }

        double result = 1.0;
        while (n > 0) {
            if (n % 2 == 1) {     // If n is odd
                result *= x;
            }
            x *= x;               // Square the base
            n /= 2;               // Divide exponent by 2
        }
        return result;
    }
};
