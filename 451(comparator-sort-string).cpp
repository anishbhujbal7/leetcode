class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> map;
        for (char c : s) {
            map[c]++;
        }
        vector<pair<char, int>> vec(map.begin(), map.end());
        sort(vec.begin(), vec.end(),
             [](auto& a, auto& b) { return a.second > b.second; });
        string res = "";
        for (auto pair : vec) {
            res += string(pair.second, pair.first);
        }
        return res;
    }
};
