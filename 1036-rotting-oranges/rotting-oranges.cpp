class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>> q;
        int fresh = 0;

        // Step 1: fill queue & count fresh
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 2){
                    q.push({i, j});
                }
                else if(grid[i][j] == 1){
                    fresh++;
                }
            }
        }

        // directions (up, down, left, right)
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        int minutes = 0;

        // Step 3: BFS
        while(!q.empty() && fresh > 0){
            int size = q.size(); // one level = one minute

            for(int i = 0; i < size; i++){
                auto [x, y] = q.front();
                q.pop();

                for(int d = 0; d < 4; d++){
                    int nx = x + dx[d];
                    int ny = y + dy[d];

                    // valid + fresh
                    if(nx >= 0 && ny >= 0 && nx < n && ny < m && grid[nx][ny] == 1){
                        grid[nx][ny] = 2; // rot it
                        fresh--;
                        q.push({nx, ny});
                    }
                }
            }

            minutes++; // one round done
        }

        // if still fresh left → impossible
        return (fresh == 0) ? minutes : -1;
    }
};