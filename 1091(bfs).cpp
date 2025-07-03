class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<bool>> visited(n,vector<bool>(n,false));
        queue<pair<int,pair<int,int>>> q;
        if(grid[0][0]==1) return -1;
        q.push({1,{0,0}});
        visited[0][0]=true;
        int len=0;
        vector<pair<int,int>> adjList={{0,1},{0,-1},{1,0},{-1,0},{1,1}, {1,-1}, {-1,1}, {-1,-1}};
        while(!q.empty()){
            int l=q.front().first;
            int row=q.front().second.first;
            int col=q.front().second.second;
            q.pop();
            len=max(len,l);
            if (row==n-1&&col==n-1) return len;
            for(auto [r,c]:adjList){
                int newRow=row+r;
                int newCol=col+c;
                if(newCol<n&&newRow<n&&newCol>=0&&newRow>=0){
                    if(grid[newRow][newCol]==0&&!visited[newRow][newCol]){
                        visited[newRow][newCol]=true;
                        q.push({l+1,{newRow,newCol}});
                       
                    }
                }
            }
        }
        return -1;
    }
};
