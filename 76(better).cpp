class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty()) return "";

        unordered_map<char, int> targetMap;
        unordered_map<char, int> windowMap;
        unordered_set<char> targetSet;

        // Step 1: Build frequency map and set from string t
        for (char c : t) {
            targetMap[c]++;
            targetSet.insert(c);
        }

        int left = 0;
        int minLen = INT_MAX;
        int minStart = 0;
        int n = s.length();

        for (int right = 0; right < n; ++right) {
            char c = s[right];

            // Step 2: Update window map if character is in target set
            if (targetSet.count(c)) {
                windowMap[c]++;
            }

            // Step 3: Check if window map matches target map
            bool isValidWindow = true;
            for (auto& [ch, count] : targetMap) {
                if (windowMap[ch] < count) {
                    isValidWindow = false;
                    break;
                }
            }

            // Step 4: If valid, try to shrink from the left
            while (isValidWindow && left <= right) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    minStart = left;
                }

                char leftChar = s[left];
                if (targetSet.count(leftChar)) {
                    windowMap[leftChar]--;
                }

                left++;

                // Recheck validity after shrinking
                for (auto& [ch, count] : targetMap) {
                    if (windowMap[ch] < count) {
                        isValidWindow = false;
                        break;
                    }
                }
            }
        }

        return (minLen == INT_MAX) ? "" : s.substr(minStart, minLen);
    }
};
