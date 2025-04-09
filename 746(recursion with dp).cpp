class Solution {
public:

    int minCost(int i,vector<int> &cost,vector<int>&dp){
        if(i<0) return 0;
        if(i==0) return cost[i];
        if(dp[i]!=-1) return dp[i];
        int option1=cost[i]+minCost(i-1,cost,dp);
        int option2=cost[i]+minCost(i-2,cost,dp);
        return dp[i]=min(option1,option2);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n= cost.size();
        vector<int> dp(n,-1);
        int output1 =minCost(n-1,cost,dp);
        int output2=minCost(n-2,cost,dp);
        return min(output1,output2);
    }
};
