class Solution {
public:
    bool canReach(vector<int>& start, vector<int>& target) {
        int x=start[0];
        int y=start[1];

        int t1=target[0];
        int t2=target[1];
        int sum = (t1-x) + (t2-y);
        if(sum%2!=0){
            return false;
        }
        else{
            return true;
        }
    }
};