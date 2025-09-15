class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n = word.size();
        vector<int> firstLower(26, -1);
        vector<int> firstUpper(26, -1);
        vector<int> lastLower(26, -1);

        for (int i = 0; i < n; i++) {
            char c = word[i];
            if (islower(c)) {
                int idx = c - 'a';
                if (firstLower[idx] == -1) {
                    firstLower[idx] = i;
                }
                lastLower[idx] = i;
            } else {
                int idx = tolower(c) - 'a';
                if (firstUpper[idx] == -1) {
                    firstUpper[idx] = i;
                }
            }
        }

        int count = 0;
        for (int i = 0; i < 26; i++) {
            // must have both lowercase and uppercase
            if (firstLower[i] != -1 && firstUpper[i] != -1) {
                // check rule: last lowercase occurs before first uppercase
                if (lastLower[i] < firstUpper[i]) {
                    count++;
                }
            }
        }
        return count;
    }
};
