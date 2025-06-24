class Solution {
public:
    bool dfs(int node, int &destination,vector<vector<int>>&adjList,vector<bool>& visited){
        if(node==destination) return true;
        visited[node]=true;
        for(auto edge:adjList[node]){
            // if(edge==destination) return true;
            if(!visited[edge]){
                if(dfs(edge,destination,adjList, visited)) return true;
            }
        }
        return false;
    }

   
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if (n==1) return true;
         vector<vector<int>> adjList(n);
        vector<bool> visited(n, false);

        // Build adjacency list
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        return dfs(source,destination,adjList, visited);
    }
};
