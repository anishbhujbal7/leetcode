class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int> map;
        for(int num : nums){
            map[num]++;
        }
        vector<pair<int,int>> vec(map.begin(), map.end());
        sort(vec.begin(), vec.end(), []( auto &a, auto &b){
            if (a.second==b.second) return a.first>b.first;
            return a.second<b.second;
        });
        vector<int> res;
        for(auto pair: vec){
            vector<int> temp(pair.second,pair.first);
           for(int num : temp){
             res.push_back(num);
           }
        }
        return res;
    }
};
