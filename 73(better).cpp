class Solution {
public:
    void rowChange(int row, int m, int n, vector<vector<int>>& matrix) {
        for (int b = 0; b < n; b++) {
            if (matrix[row][b] == 0)
                continue;
            matrix[row][b] = -1e3;
        }
    }

    void colChange(int col, int m, int n, vector<vector<int>>& matrix) {
        for (int a = 0; a < m; a++) {
            if (matrix[a][col] == 0)
                continue;
            matrix[a][col] = -1e3;
        }
    }

    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    rowChange(i, m, n, matrix);
                    colChange(j, m, n, matrix);
                }
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == -1e3) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};
