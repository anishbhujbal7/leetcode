class Solution {
public:

    int longestLength(int i, int j, string& word1, string& word2, vector<vector<int>>& dp){
        if(i >= word1.size() || j>= word2.size()) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(word1[i] == word2[j]) return dp[i][j] = 1 + longestLength(i+1, j+1, word1, word2, dp);
        else{
            dp[i][j] = max(longestLength(i,j+1, word1, word2, dp), longestLength(i+1, j, word1, word2, dp));
        }
        return dp[i][j];
    }

    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        int len = longestLength(0, 0, word1, word2, dp);
        return (m-len + n-len);
    }
};
