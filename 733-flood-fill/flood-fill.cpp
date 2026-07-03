class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>& image, int newcolor,
             int origColor) {
        if (i < 0 || j < 0 || i >= image.size() || j >= image[0].size() || 
            image[i][j] != origColor || image[i][j] == newcolor) {
            return;
        }
        image[i][j] = newcolor;
        dfs(i + 1, j, image, newcolor, origColor);
        dfs(i, j - 1, image, newcolor, origColor);
        dfs(i - 1, j, image, newcolor, origColor);
        dfs(i, j + 1, image, newcolor, origColor);
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        // dfs use hoga
       

        dfs(sr,sc, image, color, image[sr][sc]);
        return image;
    }
};