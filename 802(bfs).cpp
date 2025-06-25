class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
      int n =graph.size();
      vector<int> inDegree(n,0);
      vector<vector<int>> adjList(n);
      vector<int> res;
      for(int i =0;i<n;i++){
            for(int j:graph[i]){
                adjList[j].push_back(i);
                inDegree[i]++;
            }
        
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(inDegree[i]==0) q.push(i);
        }
        while(!q.empty()){
            int currNode= q.front();
            res.push_back(currNode);
            q.pop();
            for(int newNode:adjList[currNode]){
                inDegree[newNode]--;
                if(inDegree[newNode]==0){
                    q.push(newNode);
                }
            }
        }
        sort(res.begin(),res.end());
        return res;  
    }
};
