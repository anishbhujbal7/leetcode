class Solution {
public:
    void bfs(vector<vector<bool>>& visited, queue<pair<int, int>>& q,
             vector<pair<int, int>>& adjList, vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for (auto [r, c] : adjList) {
                int newRow = row + r;
                int newCol = col + c;
                if (newRow >= m || newCol >= n || newCol < 0 || newRow < 0)
                    continue;
                if (visited[newRow][newCol])
                    continue;
                if (heights[newRow][newCol] < heights[row][col])
                    continue;
                // now if all are false the water would flow to the next cell
                visited[newRow][newCol] = true;
                q.push({newRow, newCol});
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<pair<int, int>> adjList = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));
        queue<pair<int, int>> atlanticQ;
        queue<pair<int, int>> pacificQ;
        vector<vector<int>> res;

        // pushing in queue
        for (int i = 0; i < m; i++) {
            pacificQ.push({i, 0});
            pacific[i][0] = true;
            atlanticQ.push({i, n - 1});
            atlantic[i][n - 1] = true;
        }

        for (int j = 0; j < n; j++) {
            pacificQ.push({0, j});
            atlanticQ.push({m - 1, j});
            pacific[0][j] = true;
            atlantic[m - 1][j] = true;
        }
        bfs(pacific, pacificQ, adjList, heights);
        bfs(atlantic, atlanticQ, adjList, heights);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pacific[i][j] && atlantic[i][j])
                    res.push_back({i, j});
            }
        }
        return res;
    }
};
