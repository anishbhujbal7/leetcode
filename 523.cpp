// If two prefix sums give the same remainder, then the subarray in between is
// divisible by k.

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0;
        unordered_map<int, int> map;
        map[0] = -1;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            int reminder = sum % k;
            if (map.find(reminder) != map.end()) {
                int len = i - map[reminder];
                if (len >= 2)
                    return true;
            } else {
                map[reminder] = i;
            }
        }
        return false;
    }
};
