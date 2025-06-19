class Solution {
public:
    void bfs(vector<vector<char>>& grid, int r, int c, int m, int n) {
        queue<pair<int, int>> q;
        q.push({r, c});
        grid[r][c] = '0';  // Mark as visited

        vector<pair<int, int>> directions = {{0,1}, {0,-1}, {1,0}, {-1,0}};

        while (!q.empty()) {
            auto [curR, curC] = q.front();
            q.pop();

            for (auto [dr, dc] : directions) {
                int newR = curR + dr;
                int newC = curC + dc;

                if (newR >= 0 && newR < m && newC >= 0 && newC < n && grid[newR][newC] == '1') {
                    q.push({newR, newC});
                    grid[newR][newC] = '0';  // Mark as visited
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;

        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] == '1') {
                    count++;  // Found a new island
                    bfs(grid, r, c, m, n);  // Flood fill using BFS
                }
            }
        }

        return count;
    }
};
