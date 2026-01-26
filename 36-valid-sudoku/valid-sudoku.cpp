class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> rows[9];
        unordered_set<char> cols[9];
        unordered_set<char> boxes[9];
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                char val=board[i][j];
                if(val=='.')continue;

                int formula=3*(i/3) + (j/3);

                //check row wise
                if(rows[i].count(val))return false;
                rows[i].insert(val);

                //check col wise
                if(cols[j].count(val))return false;
                cols[j].insert(val);

                //check box
                if(boxes[formula].count(val))return false;
                boxes[formula].insert(val);
            }
        }
        return true;

    }
};