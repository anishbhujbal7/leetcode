class Solution {
public:

    int minAscii(int i, int j, string& s1, string& s2, vector<vector<int>>& dp){
        if(i >= s1.size() || j >= s2.size()) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(s1[i] == s2[j]) return dp[i][j] =  s1[i] + minAscii(i+1, j+1, s1, s2, dp);
        else{
            return dp[i][j] = max(minAscii(i, j+1, s1, s2, dp), minAscii(i+1, j, s1, s2, dp));
        }
    }

    int minimumDeleteSum(string s1, string s2) {
      int m = s1.size();
      int n = s2.size();
      vector<vector<int>> dp(m, vector<int>(n,-1));

      int sum1 = 0;
      int sum2 = 0;
      for(char c : s1){
        sum1 += c;
      }
      for(char c : s2){
        sum2 += c;
      }

      int len = minAscii(0, 0, s1, s2, dp);
      return (sum1 - len + sum2-len);  
    }
};
