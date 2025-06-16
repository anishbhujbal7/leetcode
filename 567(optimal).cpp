class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> ans(26, 0);
        for (char i : s1) {
            ans[i - 'a']++;
        }
        vector<int> s2Vec(26, 0);
        int left = 0;
        for (int right = 0; right < s2.size(); right++) {
            while (right - left + 1 > s1.size()) {
                s2Vec[s2[left] - 'a']--;
                left++;
            }
            s2Vec[s2[right] - 'a']++;
            if (right - left + 1 == s1.size() && ans == s2Vec)
                return true;
        }
        return false;
    }
};
