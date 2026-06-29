class Solution {
public:
void dfs(int i,int j,vector<vector<bool>> &vis,vector<vector<char>>& board,int m,int n){
    // Base condition
        if (i < 0 || j < 0 || i >= m || j >= n ||
            board[i][j] == '.' || vis[i][j])
            return;

        vis[i][j] = true;

        dfs(i - 1, j, vis, board, m, n); // up
        dfs(i + 1, j, vis, board, m, n); // down
        dfs(i, j - 1, vis, board, m, n); // left
        dfs(i, j + 1, vis, board, m, n); // right

    

}
    int countBattleships(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        vector<vector<bool>>vis(m,vector<bool>(n,false));
        int cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='X' && !vis[i][j]){
                    dfs(i,j,vis,board,m,n);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};