class Solution {
public:
    bool ways(int i, int j, vector<vector<int>>& dp, string& s1, string& s2, string& s3) {
        if (i + j == s3.size()) return true;
        if (dp[i][j] != -1) return dp[i][j];

        bool ans = false;

        // Try taking a char from s1
        if (i < s1.size() && s1[i] == s3[i + j]) {
            ans |= ways(i + 1, j, dp, s1, s2, s3);
        }

        // Try taking a char from s2
        if (j < s2.size() && s2[j] == s3[i + j]) {
            ans |= ways(i, j + 1, dp, s1, s2, s3);
        }

        return dp[i][j] = ans;
    }

    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size(), m = s2.size();
        if (n + m != s3.size()) return false;

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return ways(0, 0, dp, s1, s2, s3);
    }
};
