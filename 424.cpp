class Solution {
public:
    int characterReplacement(string s, int k) {
        int max_len = 0, max_count = 0, left = 0;
        unordered_map<char, int> charSet;

        for (int right = 0; right < s.length(); right++) {
            char c = s[right];
            charSet[c]++;
            max_count = max(max_count, charSet[c]); // Track the highest frequency

            // If replacements needed exceed k, shrink window
            while ((right - left + 1) - max_count > k) {
                charSet[s[left]]--;
                left++;
            }

            max_len = max(max_len, right - left + 1); // Update max length
        }

        return max_len;
    }
};
