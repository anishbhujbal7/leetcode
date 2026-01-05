class Solution {
public:

    int countWays(vector<int>& nums, vector<int>& dp, int target){
        if(target == 0) return 1;
        if(target<0) return 0;
        if(dp[target] != -1) return dp[target];
        int ways = 0;
        for(int num : nums){
            ways += countWays(nums, dp, target-num); 
        }
        return dp[target] = ways;
    }

    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1,-1);
        int totalWays = countWays(nums, dp, target);
        return totalWays;

    }
};
