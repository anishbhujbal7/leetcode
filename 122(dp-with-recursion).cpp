class Solution {
public:

    int bestProfit(int  i, int canBuy, vector<int>& prices, vector<vector<int>> &dp){
        int  profit = 0;
        if(i == prices.size()) return profit = 0;
        if(dp[i][canBuy] != -1) return profit = dp[i][canBuy];
        if(canBuy){
            profit = max(-prices[i] + bestProfit(i+1, 0, prices, dp), bestProfit(i+1, 1, prices, dp));
        }else{
            profit = max(prices[i] + bestProfit(i+1, 1, prices, dp), bestProfit(i+1, 0, prices, dp));
        }
        return dp[i][canBuy] = profit;
    }

   

    int maxProfit(vector<int>& prices) {
       int n = prices.size();
       vector<vector<int>> dp(n, vector<int>(2,-1));
       return bestProfit(0, 1, prices, dp); 
    }
};
