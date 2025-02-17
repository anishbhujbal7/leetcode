class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> hashMap;
        for(const string& str:strs){
            string sortedstr=str;
            sort(sortedstr.begin(),sortedstr.end());
            hashMap[sortedstr].push_back(str);
        }
        vector<vector<string>> result;
        for(auto& pair:hashMap){
            result.push_back(pair.second);
        }
        return result;

    }
};
