class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int>candy(n,1); //initially 1
        int sum=0;
        // checking left to right to find the higher rating
        for(int i=1;i<n;i++)
        {
            if(ratings[i]>ratings[i-1]){
                candy[i]=candy[i-1]+1;
            }
        }

        // checking right to left to find the higher rating
        for(int i=n-2;i>=0;i--){
            if(ratings[i]>ratings[i+1]){
                candy[i]=max(candy[i],candy[i+1]+1);
            }
        }

        // summation
        for(int i=0;i<n;i++){
            sum+=candy[i];
        }
        return sum;
    }
};