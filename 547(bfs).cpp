class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adjList(n);
        
        for(auto i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(isConnected[i][j] == 1) adjList[i].push_back(j);
            }
        }
        vector<bool> visited(n, false);
        queue<int> q;
        int count =0;
        for(int i =0; i<n; i++){
            if(!visited[i]){
                q.push(i);
                count++;
            }
            while(!q.empty()){
                int currCity = q.front();
                q.pop();
                visited[currCity] = true;
                for(auto nextCity : adjList[currCity]){
                    if(!visited[nextCity]){
                        q.push(nextCity);
                        visited[nextCity] = true;
                    }
                }
            }
        }
        return count;
    }
};
