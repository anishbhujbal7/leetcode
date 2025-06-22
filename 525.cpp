class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int prefixSum = 0;
        unordered_map<int, int> map;
        int maxLen = 0;
        map[0] = -1;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                prefixSum += -1;
            } else {
                prefixSum += 1;
            }
            if (map.find(prefixSum) != map.end()) {
                int len = i - map[prefixSum];
                maxLen = max(len, maxLen);
            } else {
                map[prefixSum] = i;
            }
        }
        return maxLen;
    }
};
