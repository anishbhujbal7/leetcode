class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> res;
        queue<vector<int>> q;
        q.push({0});
        int n= graph.size();
        while(!q.empty()){
            vector<int> path=q.front();
            int pathEnding=path.back();
            q.pop();
            if(pathEnding==n-1){
                res.push_back(path);
            }
            for(auto nextNode:graph[pathEnding]){
                vector<int> newPath=path;
                newPath.push_back(nextNode);
                q.push(newPath);
            }
        }

        return res;
    }
};
