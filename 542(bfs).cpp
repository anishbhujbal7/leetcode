class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> dist(m, vector<int>(n,0));
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<int, int>> q;
        vector<pair<int, int>> adjList = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        for(int i = 0; i<m; i++){
            for(int j =0; j<n; j++){
                if(mat[i][j] == 0){
                    visited[i][j] = true;
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for(auto [r, c] : adjList){
                int newRow = row + r;
                int newCol = col + c;
                if(newRow < m && newCol<n && newRow>=0 && newCol>=0 && !visited[newRow][newCol]){
                    dist[newRow][newCol] = dist[row][col] + 1;
                    q.push({newRow, newCol});
                    visited[newRow][newCol] = true;
                }
            }
        }
        return dist;
    }
};
