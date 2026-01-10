class Solution {
public:
    int solve(int i, int j, string& text1, string& text2,
              vector<vector<int>>& dp) {
        
        //  Base case: reached end of either string
        if (i == text1.size() || j == text2.size())
            return 0;

        //  If already computed
        if (dp[i][j] != -1)
            return dp[i][j];

        //  If characters match
        if (text1[i] == text2[j]) {
            dp[i][j] = 1 + solve(i + 1, j + 1, text1, text2, dp);
        }
        //  If characters do NOT match
        else {
            dp[i][j] = max(
                solve(i + 1, j, text1, text2, dp),
                solve(i, j + 1, text1, text2, dp)
            );
        }

        return dp[i][j];
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(0, 0, text1, text2, dp);
    }
};
