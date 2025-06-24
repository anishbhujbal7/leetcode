class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList(numCourses);
        vector<int> inDegree(numCourses, 0);
        for (auto i : prerequisites) {
            int parent = i[1];
            int child = i[0];
            adjList[parent].push_back(child);
            inDegree[child]++;
        }
        queue<int> q;
        int visited = 0;
        for (int i = 0; i < numCourses; i++) {
            if (inDegree[i] == 0)
                q.push(i);
        }
        vector<int> ans;
        while (!q.empty()) {
            int currNode = q.front();
            ans.push_back(currNode);
            q.pop();
            visited++;
            for (auto newNode : adjList[currNode]) {
                inDegree[newNode]--;
                if (inDegree[newNode] == 0)
                    q.push(newNode);
            }
        }
        return (visited == numCourses) ? ans : ans = {};
    }
};
