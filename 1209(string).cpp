class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<char, int>> vec;
        for (char c : s) {
            if (!vec.empty() && vec.back().first == c) {
                vec.back().second++;
                if (vec.back().second == k) {
                    vec.pop_back();
                }
            } else {
                vec.push_back({c, 1});
            }
        }
        string res = "";
        for (auto pair : vec) {
            res += string(pair.second, pair.first);
        }
        return res;
    }
};
