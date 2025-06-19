class Solution {
public:
    void dfs(vector<vector<int>>& image, int r, int c, int color,
             int originalColor, int m, int n) {
        if (r < 0 || r >= m || c < 0 || c >= n || image[r][c] != originalColor)
            return;
        image[r][c] = color;
        dfs(image, r, c + 1, color, originalColor, m, n);
        dfs(image, r, c - 1, color, originalColor, m, n);
        dfs(image, r + 1, c, color, originalColor, m, n);
        dfs(image, r - 1, c, color, originalColor, m, n);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        int originalColor = image[sr][sc];
        if (color == originalColor)
            return image;
        int m = image.size();
        int n = image[0].size();
        dfs(image, sr, sc, color, originalColor, m, n);
        return image;
    }
};
