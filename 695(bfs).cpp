class Solution {
public:
    int bfs(vector<vector<int>>& grid, int r, int c, int m, int n) {

        vector<vector<int>> adjList = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        queue<pair<int, int>> q;
        q.push({r, c});
        grid[r][c] = 0;
        int currentLen = 1;
        while (!q.empty()) {
            auto [row, col] = q.front();
            q.pop();
            for (auto pair : adjList) {
                int newRow = row + pair[0];
                int newCol = col + pair[1];
                if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n &&
                    grid[newRow][newCol] == 1) {
                    currentLen++;
                    q.push({newRow, newCol});
                    grid[newRow][newCol] = 0;
                }
            }
        }
        return currentLen;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int maxLen = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    int area = bfs(grid, i, j, m, n);
                    maxLen = max(maxLen, area);
                }
            }
        }

        return maxLen;
    }
};
