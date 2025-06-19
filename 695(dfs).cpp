class Solution {
public:
    int dfs(vector<vector<int>>& grid, int r, int c, int m, int n) {
        // base cases
        if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] != 1)
            return 0;

        grid[r][c] = 0; // mark as visited
        int currLen = 1;

        currLen += dfs(grid, r + 1, c, m, n);
        currLen += dfs(grid, r - 1, c, m, n);
        currLen += dfs(grid, r, c + 1, m, n);
        currLen += dfs(grid, r, c - 1, m, n);

        return currLen;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int maxLen = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    int area = dfs(grid, i, j, m, n);
                    maxLen = max(maxLen, area);
                }
            }
        }

        return maxLen;
    }
};
