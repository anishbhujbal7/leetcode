class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int freshCnt = 0;
        int time = 0;
        vector<vector<int>> adjList = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        queue<pair<pair<int, int>, int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                } else if (grid[i][j] == 1)
                    freshCnt++;
            }
        }
        if (freshCnt == 0)
            return 0;
        while (!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();
            time = max(time, t);
            for (auto pair : adjList) {
                int newRow = r + pair[0];
                int newCol = c + pair[1];
                if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n &&
                    grid[newRow][newCol] == 1) {
                    q.push({{newRow, newCol}, t + 1});
                    grid[newRow][newCol] = 2;
                    freshCnt--;
                }
            }
        }

        return (freshCnt == 0) ? time : -1;
    }
};
