class Solution {
public:
void dfs(int i,int j,vector<vector<bool>>& vis, vector<vector<int>>& grid,int n,int m){
    if(i<0 || j<0 || i>=n || j>=m || vis[i][j] || grid[i][j]!=1){
        return;
    }
    vis[i][j]=true;
    dfs(i+1,j,vis,grid,n,m);
    dfs(i-1,j,vis,grid,n,m);
    dfs(i,j+1,vis,grid,n,m);
    dfs(i,j-1,vis,grid,n,m);
}
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<bool>>vis(n,vector<bool>(m,false));
        int no_of_lands=0;

        for(int i=0;i<n;i++){//will check the row first and last row
            if(grid[i][0]==1 && !vis[i][0]){
                dfs(i,0,vis,grid,n,m);
            }
            if(grid[i][m-1]==1 && !vis[i][m-1]){
                dfs(i,m-1,vis,grid,n,m);
            }
        }

        for(int i=0;i<m;i++){//will check the col first and last col
            if(grid[0][i]==1 && !vis[0][i]){
                dfs(0,i,vis,grid,n,m);
            }
            if(grid[n-1][i]==1 && !vis[n-1][i]){
                dfs(n-1,i,vis,grid,n,m);
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    no_of_lands++;
                }
            }
        }
        return no_of_lands;

    }
};