class Solution {
public:
    int numSquares(int n) {
        queue<pair<int, int>> q;
        int num = 1;
        while (num * num <= n) {
            q.push({num * num, 1});
            num++;
        }
        int minMoves = INT_MAX;

        vector<bool> visited(n + 1, false);

        while (!q.empty()) {
            int currSum = q.front().first;
            int moves = q.front().second;
            q.pop();
            if (currSum == n)
                minMoves = min(minMoves, moves);
            int i = 1;
            while (i * i <= n - currSum) {
                int newSum = currSum + (i * i);
                if (!visited[newSum]) {
                    q.push({newSum, moves + 1});
                    visited[newSum] = true;
                }
                i++;
            }
        }
        return minMoves;
    }
};
