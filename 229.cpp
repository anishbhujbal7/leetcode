class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> hashmap;
        int n= nums.size();
        vector<int> res;
        for(int i=0;i<n;i++){
            hashmap[nums[i]]++;
        }
        for(auto i:hashmap){
            if (i.second>n/3) res.push_back(i.first);
        }
        return res;
    }
};
