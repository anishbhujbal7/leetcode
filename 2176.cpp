class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        unordered_map<int,vector<int>> map;
        for(int i = 0; i<nums.size(); i++){
            map[nums[i]].push_back(i);
        }
        int count = 0;
        for(auto pair : map){
            if(pair.second.size()>=2){
                for(int i = 0; i< pair.second.size()-1;i++){
                    for(int j = i+1; j<pair.second.size();j++){
                        if((pair.second[i]*pair.second[j])%k==0) count++;
                    }
                }
            }
        }
        return count;
    }
};
