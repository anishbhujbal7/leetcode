class Solution {
public:

    int findLen(int i, int j, vector<vector<int>>& dp, unordered_map<int, int>& map, vector<int>& arr){
        if(dp[i][j] != -1) return dp[i][j];
        int prev = arr[j] - arr[i];
        if(prev >= arr[i] || map.find(prev) == map.end()){
            return dp[i][j] = 2;
        }
        int k = map[prev];
        dp[i][j] = findLen(k, i, dp, map, arr)+1;
        return dp[i][j];
    }

    int lenLongestFibSubseq(vector<int>& arr) {
        unordered_map<int, int> map;
        int n = arr.size();
        for(int i = 0; i<n; i++){
            map[arr[i]] = i;
        }
        vector<vector<int>> dp(n, vector<int>(n,-1));
        int ans = 0;
        for(int j= 0; j<n; j++){
            for(int i= 0; i<j; i++){
                ans = max(ans, findLen(i ,j, dp, map, arr));
            }
        }
        return (ans>=3) ? ans : 0;
    }
};
