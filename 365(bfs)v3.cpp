class Solution {
public:
    pair<int, int> fillJug(int a, int b, int c) {
        // int fill = b-a;
        return {b, c};
    }

    pair<int, int> pourWater(int a, int b, int c) {
        if (c - a == b)
            return {b, 0};
        else if (c - a > b)
            return {a + b, 0};
        else {
            return {a + (c - a), b - (c - a)};
        }
    }

    bool canMeasureWater(int x, int y, int target) {
        int curr = 0;
        queue<pair<int, int>> q;
        vector<vector<bool>> visited(x + 1, vector<bool>(y + 1, false));

        q.push({0, 0});

        visited[0][0] = true;
        while (!q.empty()) {

            int firstJug = q.front().first;
            int secondJug = q.front().second;
            q.pop();
            int capacity = firstJug + secondJug;
            if (capacity == target || firstJug == target || secondJug == target)
                return true;
            // fill either jug
            auto [fx1, fy1] = fillJug(firstJug, x, secondJug);
            // int c1 = fx1+fy1;

            if (!visited[fx1][fy1]) {
                visited[fx1][fy1] = true;
                q.push({fx1, fy1});
            }
            auto [fy2, fx2] = fillJug(secondJug, y, firstJug);
            // int c2 = fy2+fx2;

            if (!visited[fx2][fy2]) {
                visited[fx2][fy2] = true;
                q.push({fx2, fy2});
            }
            // completely empty
            int cx1 = 0, cy1 = secondJug;
            // int c3 = cx1+cy1;

            if (!visited[cx1][cy1]) {
                visited[cx1][cy1] = true;
                q.push({cx1, cy1});
            }
            int cx2 = firstJug, cy2 = 0;
            // int c4 = cx2+cy2;

            if (!visited[cx2][cy2]) {
                visited[cx2][cy2] = true;
                q.push({cx2, cy2});
            }
            // pour water foem one jug into another
            auto [px1, py1] = pourWater(firstJug, secondJug, x);
            // int c5 = px1+py1;

            if (!visited[px1][py1]) {
                visited[px1][py1] = true;
                q.push({px1, py1});
            }
            auto [py2, px2] = pourWater(secondJug, firstJug, y);
            // int c6 = px2+py2;

            if (!visited[px2][py2]) {
                visited[px2][py2] = true;
                q.push({px2, py2});
            }
        }
        return false;
    }
};
