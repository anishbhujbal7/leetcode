class Solution {
public:
    int singleNumber(vector<int>& nums) {
       int n=nums.size();
       unordered_map<int,int> countMap;
       for(int i=0;i<n;i++){
        countMap[nums[i]]++;
       }
       for (auto i:countMap){
        if(i.second==1) return i.first;
       }
       return -1;
    }
};
