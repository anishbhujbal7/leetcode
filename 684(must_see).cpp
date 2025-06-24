class Solution {
public:

    bool isCycle(int src, int target, vector<vector<int>> &adjList, vector<bool> &visited){
        visited[src]=true;
        queue<int> q;
        q.push(src);
        while(!q.empty()){
            int currNode=q.front();
            q.pop();
            if(currNode==target) return true;
            for( auto newNode: adjList[currNode]){
                if(!visited[newNode]){
                    visited[newNode]=true;
                    q.push(newNode);
                }
            }
        }
        return false;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> adjList(n+1);
        vector<int> ans;
        for(auto edge: edges){
            int u = edge[0];
            int v = edge[1];
            vector<bool> visited(n+1,false);
            if(isCycle(u,v,adjList,visited)) ans=edge;
            else{
                adjList[u].push_back(v);
                adjList[v].push_back(u);
            }
        }
        return ans;
    }
};
