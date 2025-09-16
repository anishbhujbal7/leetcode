class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<char> map(26, '*');
        vector<bool> ignore(26, false);
        for (char c : word) {
            if (islower(c)) {
                if (map[c - 'a'] == '+') {
                    ignore[c - 'a'] = true;
                    map[c - 'a'] = '*';
                } else {
                    map[c - 'a'] = '@';
                }
            } else {
                if (map[tolower(c) - 'a'] == '*') {
                    ignore[tolower(c) - 'a'] = true;
                } else {
                    map[tolower(c) - 'a'] = '+';
                }
            }
        }
        int count = 0;
        for (int i = 0; i < 26; i++) {
            if (map[i] == '+' && !ignore[i]) {
                count++;
            }
        }
        return count;
    }
};
