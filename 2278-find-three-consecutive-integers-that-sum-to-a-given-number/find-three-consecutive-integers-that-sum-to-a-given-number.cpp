class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        if(num%3!=0)return {};
        long long rem=num/3;
        return {rem-1,rem,rem+1};
    }
};