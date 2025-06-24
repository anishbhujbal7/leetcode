
// you only take the course if it has no prequisite
// inDegree tells us ith course depends on how many courses
// with help of inDegree we determine from where the bfs should start

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList(numCourses);
        vector<int> inDegree(numCourses, 0);
        int visited = 0;
        for (auto i : prerequisites) {
            int child = i[0];
            int parent = i[1];
            adjList[parent].push_back(child);
            inDegree[child]++;
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int currNode = q.front();
            q.pop();
            visited++;
            for (auto newNode : adjList[currNode]) {
                inDegree[newNode]--;
                if (inDegree[newNode] == 0)
                    q.push(newNode);
            }
        }
        return visited == numCourses;
    }
};
