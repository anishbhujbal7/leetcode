class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
      int n = grid.size();
      vector<vector<int>> dp(n,vector<int>(n,-1));
      int result=INT_MAX;
      for(int a =0;a<n;a++){
        result=min(result,pathfinder(0,a,n,grid,dp));
      }
      return result;  
    }
    int pathfinder(int i,int j,int n,vector<vector<int>>& grid,vector<vector<int>>& dp){
       if (i==n-1) return grid[i][j];
       if(dp[i][j]!=-1) return dp[i][j];
       int minPath= INT_MAX;
       for (int p=0;p<n;p++){
        if(p!=j){
            minPath=min(minPath,grid[i][j]+ pathfinder(i+1,p,n,grid,dp));
        }
       }
       return dp[i][j]=minPath;
    }
};
