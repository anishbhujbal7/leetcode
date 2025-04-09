class Solution {
public:

    int waysFinder(int i, vector<int> &dp){
        if(i==1) return dp[i]=1;
        if(i==2) return dp[i]=2;
        if(dp[i]!=-1) return dp[i];
        int steps=1+waysFinder(i-1,dp)+waysFinder(i-2,dp);
        return dp[i]=steps;
    }
    int climbStairs(int n) {
        vector<int> dp(n,-1);
        return waysFinder(n,dp);
    }
};
