class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> next=board;
        int n=board.size();
        int m=board[0].size();

        // directions for 8 neighbours
        int dx[8] = {0,0,1,1,1,-1,-1,-1};
        int dy[8] = {1,-1,1,-1,0,0,1,-1};

        for(int row=0;row<n;row++){
            for(int col=0;col<m;col++){
                int cnt=0;
                for(int i=0;i<8;i++){
                    int curr_x=row+dx[i];
                    int curr_y=col+dy[i];
                    if(curr_x >=0 && curr_x < n && curr_y >=0 && curr_y <m ){
                        if(board[curr_x][curr_y] == 1){
                            cnt++;
                        }
                    }
                }
                // Applying the rule
                if(board[row][col]==1){
                    if(cnt<2 || cnt>3){
                        next[row][col]=0;
                    }
                    else{
                        next[row][col]=1;
                    }
                }
                else{
                    if(cnt==3){
                        next[row][col]=1;
                    }
                    else{
                        next[row][col]=0;
                    }
                }
            }
        }
        board=next;

    }
};