class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sum=0;
        int a;
        for(int i=0;i<prices.size()-1;i++){
            a=prices[i+1]-prices[i];
            if(a>0){
                sum+=a;
            }
            
        }
        return sum;
    }
};