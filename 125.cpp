class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.size() - 1;
        
        while (left < right) {
            // Skip non-alphabetic characters
            while (left < right && !isAlpha(s[left])) left++;
            while (left < right && !isAlpha(s[right])) right--;
            
            // Compare characters (case insensitive)
            if (tolower(s[left]) != tolower(s[right])) {
                return false;
            }

            left++;
            right--;
        }
        return true;
    }

    bool isAlpha(char c) {
        return ('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z'||('0' <= c && c <= '9'));
    }
};
