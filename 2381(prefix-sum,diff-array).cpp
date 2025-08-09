class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> diffArray(n+1, 0);
        vector<int> totalShift(n, 0);

        for (auto &num : shifts) {
            int start = num[0];  // No -1 here
            int end = num[1];
            int direction = num[2];

            if (direction == 1) { // shift forward
                diffArray[start] = (diffArray[start] + 1) % 26;
                diffArray[end + 1] = (diffArray[end + 1] - 1 + 26) % 26;
            } else { // shift backward
                diffArray[start] = (diffArray[start] - 1 + 26) % 26;
                diffArray[end + 1] = (diffArray[end + 1] + 1) % 26;
            }
        }

        totalShift[0] = diffArray[0];
        if (totalShift[0] < 0) totalShift[0] += 26;

        for (int j = 1; j < n; j++) {
            totalShift[j] = (totalShift[j-1] + diffArray[j]) % 26;
            if (totalShift[j] < 0) totalShift[j] += 26;
        }

        for (int i = 0; i < n; i++) {
            char c = s[i];
            s[i] = ((c - 'a' + totalShift[i]) % 26) + 'a';
        }

        return s;
    }
};
