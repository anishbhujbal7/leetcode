class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> hashMap;
        int sumCnt=0;
        int prefixSum=0;
        hashMap[0]=1;
        for(int i=0;i<nums.size();i++){
            prefixSum=prefixSum+nums[i];
            if (hashMap.find(prefixSum - k) != hashMap.end()){
                sumCnt=sumCnt+hashMap[prefixSum-k];
            }
            hashMap[prefixSum]++;
        }
        return sumCnt;
    }
};
