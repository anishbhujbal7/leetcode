class Solution {
public:

    bool canCross(vector<vector<int>>& grid){
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        queue<pair<int,int>> q;
        vector<pair<int, int>> adjList={{0,1},{0,-1},{1,0},{-1,0}};
        for(int i =0;i<n;i++){
            if (grid[0][i]==0){
                q.push({0,i});
                visited[0][i]=true;
            }
        }
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            if(row==m-1) return true;
            for(auto[r,c]:adjList){
                int newRow=row+r;
                int newCol=col+c;
                if(newRow<m&&newCol<n&&newRow>=0&&newCol>=0){
                    if(!visited[newRow][newCol]&&grid[newRow][newCol]==0){
                        q.push({newRow,newCol});
                        visited[newRow][newCol]=true;
                    }
                }
            }
        }
        return false;
    }


    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int left=1;
        int right=cells.size();
        int ans=0;
        while(left<=right){
            int mid = left+(right-left)/2;
            vector<vector<int>> grid(row,vector<int>(col,0));
            for(int i=0;i<mid;i++){
                int r=cells[i][0]-1;
                int c=cells[i][1]-1;
                grid[r][c]=1;
            }
            if(canCross(grid)){
                ans= mid;
                left=mid+1;
            }
            else{
                right=mid-1;
            }
        }
        return ans;
    }
};
