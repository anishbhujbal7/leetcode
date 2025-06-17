class Solution {
public:
    int findLHS(vector<int>& nums) {
      int n =  nums.size();
      unordered_map<int ,int> hashMap;
      int maxLen=0;
      for(int i:nums){
        hashMap[i]++;
      }
      for(int i: nums){
        if(hashMap.find(i+1)!=hashMap.end()){
            maxLen=max(maxLen,hashMap[i]+hashMap[i+1]);
        }
      }
      return maxLen;
    }
};
