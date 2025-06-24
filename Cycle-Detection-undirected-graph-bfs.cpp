bool bfsCycle(int start, vector<vector<int>>& adj, vector<bool>& visited) {
    queue<pair<int, int>> q;
    visited[start] = true;
    q.push({start, -1});

    while (!q.empty()) {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push({neighbor, node});
            } else if (neighbor != parent) {
                return true; // cycle detected
            }
        }
    }

    return false;
}

bool hasCycle(int n, vector<vector<int>>& edges) {
    vector<vector<int>> adj(n + 1);
    for (auto& edge : edges) {
        int u = edge[0], v = edge[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> visited(n + 1, false);
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            if (bfsCycle(i, adj, visited)) return true;
        }
    }

    return false;
}
