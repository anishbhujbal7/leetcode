class Solution {
public:

    int game(int  l, int r, vector<int>& nums, vector<vector<int>>& dp){
        if(l == r) return nums[l];
        if(dp[l][r] != -1) return dp[l][r];
        int leftPick = nums[l] - game(l+1, r, nums, dp);
        int rightPick = nums[r] - game(l,  r-1, nums, dp);
        return dp[l][r] = max(leftPick, rightPick);
    }

    bool predictTheWinner(vector<int>& nums) {
      int n = nums.size();
      vector<vector<int>> dp(n, vector<int>(n,-1));
      return game(0, n-1, nums, dp)>=0;  
    }
};486()
