class Solution {
public:
    int sumFinder(int i, vector<int>& nums, vector<int>& dp) {
        if (i == 0) return dp[i] = nums[0];

        if (dp[i] != INT_MIN) return dp[i];

        // Either start a new subarray at i or extend the one ending at i-1
        int include = nums[i] + sumFinder(i - 1, nums, dp);
        dp[i] = max(nums[i], include);
        return dp[i];
    }

    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, INT_MIN);
        
        int result = INT_MIN;
        for (int i = 0; i < n; i++) {
            result = max(result, sumFinder(i, nums, dp));
        }
        return result;
    }
};
