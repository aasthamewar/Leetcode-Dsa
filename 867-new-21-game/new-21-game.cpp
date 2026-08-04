class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        // double result=0;
        // vector<double>p(n+1,0.0);
        // p[0]=1;
        // for(int i=1;i<=n;i++){
        //     for(int j=1;j<=maxPts;j++){
        //         if(i-j>=0 && i-j<k){
        //             p[i]+=p[i-j]/maxPts;
        //         }
        //     }
        // }
        // for(int i=k;i<=n;i++){
        //     result+=p[i];
        // }
        // return result;

        if (k == 0 || n >= k - 1 + maxPts) return 1.0;

        vector<double> dp(maxPts, 0.0);
        dp[0] = 1.0;

        double windowSum = 1.0, result = 0.0;

        for (int i = 1; i <= n; i++) {
            double prob = windowSum / maxPts;

            if (i < k) {
                windowSum += prob;
            } else {
                result += prob;
            }

            if (i >= maxPts) {
                windowSum -= dp[i % maxPts];
            }

            dp[i % maxPts] = prob;
        }

        return result;
    }
};