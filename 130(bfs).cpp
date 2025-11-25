class Solution {
public:
    void floodFill(int i, int j, vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        queue<pair<int, int>> q;
        q.push({i, j});
        board[i][j] = '#';
        vector<pair<int, int>> adjList = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for (auto dir : adjList) {
                int newRow = row + dir.first;
                int newCol = col + dir.second;
                if (newRow >= 0 && newCol >= 0 && newRow < m && newCol < n) {
                    if(board[newRow][newCol] == 'O'){
                        q.push({newRow, newCol});
                        board[newRow][newCol] = '#';
                    }
                }
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O') {
                    if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
                        floodFill(i, j, board);
                    }
                }
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                if(board[i][j] == '#')  board[i][j] = 'O';
            }
        }
    }
};
