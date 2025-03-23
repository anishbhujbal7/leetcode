class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>numsMap;
        int n= nums.size();
        for(int i=0;i<n;i++){
            numsMap[nums[i]]++;
        }
        for(auto i:numsMap){
            if(i.second>n/2){
                return i.first;
            }
        }
        return -1;
    }
};
