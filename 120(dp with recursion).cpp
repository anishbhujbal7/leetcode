class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n= triangle.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        int a=0,b=0;
        return pathfinder(a,b,triangle,n,dp);
    }

    int pathfinder(int i,int j,vector<vector<int>>& triangle,int n,vector<vector<int>>& dp){
      if(i==n-1){
        return triangle[i][j];
        
      }
      if (dp[i][j]!=-1) return dp[i][j];
      int down=triangle[i][j]+pathfinder(i+1,j,triangle,n,dp);
      int right=triangle[i][j]+pathfinder(i+1,j+1,triangle,n,dp);
      return dp[i][j]=min(down,right);
       
    }
};
