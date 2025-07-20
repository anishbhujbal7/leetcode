class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        for(int i:nums){
            map[i]++;
        }
        int count  =0;
        for(auto i:map){
            if(map.find(k+i.first)!=map.end()) count+=i.second*map[i.first+k];
        }
        return count;
    }
};
