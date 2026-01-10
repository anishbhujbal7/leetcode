class Solution {
public:
    // this function gives the number of ways to make up the amount  if we start from index i
    int findWays(int i, int amount, vector<vector<int>>& dp, vector<int>& coins){
        if(amount == 0) return 1;
        // if amount becomes 0 that means we have found a valid combination 
        if(i >= coins.size()) return 0;
        // if i exceeds the size of coins that means  we have tried  all the coins yet we are unable to find a valid combination

        if(dp[i][amount] != -1) return dp[i][amount];
        int ways = 0;

        // we can take the current coin if the remaining amount is greater than or equal to the current  coin
        if(amount >= coins[i]){
            ways += findWays(i, amount - coins[i], dp, coins);
        }

        //  if not then we skip the current coin
        ways += findWays(i+1, amount, dp, coins);
        return dp[i][amount] = ways;
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1,-1));
        // here we return the number of ways to make up the amount if we start from index 0. This contains the number of ways if we start from idex 1,2,3 and so on
        return findWays(0, amount, dp, coins);
    }
};
