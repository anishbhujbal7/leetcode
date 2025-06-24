class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n, false);

        queue<int> q;
        visited[0] = true;
        for (auto i : rooms[0]) {
            q.push(i);
            visited[i] = true;
        }
        while (!q.empty()) {
            int room = q.front();
            q.pop();
            for (auto newRoom : rooms[room]) {
                if (!visited[newRoom]) {
                    q.push(newRoom);
                    visited[newRoom] = true;
                }
            }
        }
        for (auto i : visited) {
            if (i == false)
                return false;
        }
        return true;
    }
};
