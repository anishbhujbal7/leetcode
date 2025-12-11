class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {

        unordered_map<int, vector<int>> rows, cols;

        // Build row & column maps
        for (auto &b : buildings) {
            int r = b[0], c = b[1];
            rows[r].push_back(c);
            cols[c].push_back(r);
        }

        // Sort row and column lists
        for (auto &p : rows) sort(p.second.begin(), p.second.end());
        for (auto &p : cols) sort(p.second.begin(), p.second.end());

        int covered = 0;

        for (auto &b : buildings) {
            int r = b[0], c = b[1];

            auto &rowList = rows[r];
            auto &colList = cols[c];

            // Binary search positions
            int colPos = lower_bound(rowList.begin(), rowList.end(), c) - rowList.begin();
            int rowPos = lower_bound(colList.begin(), colList.end(), r) - colList.begin();

            bool left = (colPos > 0);
            bool right = (colPos + 1 < rowList.size());

            bool up = (rowPos > 0);
            bool down = (rowPos + 1 < colList.size());

            if (left && right && up && down)
                covered++;
        }

        return covered;
    }
};
