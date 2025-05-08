class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int start = 0;
        int m = matrix.size();
        int n = matrix[0].size();
        int totalNo = m * n;
        int eleCnt = 0;

        int rowEnd = m;
        int colEnd = n;

        while (eleCnt < totalNo) {
            int i = start;

            // Left to Right
            for (int j = start; j < colEnd && eleCnt < totalNo; j++) {
                ans.push_back(matrix[i][j]);
                eleCnt++;
            }

            // Top to Bottom
            for (int i = start + 1; i < rowEnd && eleCnt < totalNo; i++) {
                ans.push_back(matrix[i][colEnd - 1]);
                eleCnt++;
            }

            // Right to Left
            for (int j = colEnd - 2; j >= start && eleCnt < totalNo; j--) {
                ans.push_back(matrix[rowEnd - 1][j]);
                eleCnt++;
            }

            // Bottom to Top
            for (int i = rowEnd - 2; i > start && eleCnt < totalNo; i--) {
                ans.push_back(matrix[i][start]);
                eleCnt++;
            }

            start++;
            rowEnd--;
            colEnd--;
        }

        return ans;
    }
};
