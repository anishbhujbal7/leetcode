class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source,
                   int destination) {
        if (n == 1)
            return true;
        vector<vector<int>> adjList(n);
        queue<int> q;
        vector<bool> visited(n);
        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        q.push(source);
        visited[source] = true;
        while (!q.empty()) {
            int front = q.front();
            q.pop();
            // visited[front]=true;
            for (auto newEdge : adjList[front]) {
                if (newEdge == destination)
                    return true;
                if (!visited[newEdge]) {
                    q.push(newEdge);
                    visited[newEdge] = true;
                }
            }
        }
        return false;
    }
};
