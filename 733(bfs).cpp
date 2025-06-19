class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        int originalColor = image[sr][sc];
        if (color == originalColor)
            return image;
        vector<pair<int, int>> adjList = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        queue<pair<int, int>> q;
        q.push({sr, sc});
        image[sr][sc] = color;
        int m = image.size();
        int n = image[0].size();
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            for (auto [newR, newC] : adjList) {
                int newRow = newR + r;
                int newCol = newC + c;
                if (newRow >= 0 && newCol >= 0 && newRow < m && newCol < n &&
                    image[newRow][newCol] == originalColor) {
                    q.push({newRow, newCol});
                    image[newRow][newCol] = color;
                }
            }
        }
        return image;
    }
};
