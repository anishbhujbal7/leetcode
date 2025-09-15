class Solution {
public:
    string removeDuplicates(string s) {
        vector<char> vec;
        for (char c : s) {
            if (!vec.empty() && vec.back() == c) {
                vec.pop_back();
            } else {
                vec.push_back(c);
            }
        }
        return string(vec.begin(), vec.end());
    }
};
