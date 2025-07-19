class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if (k < 0) return 0; // Absolute difference can't be negative

        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }

        int count = 0;
        for (auto& [num, val] : freq) {
            if (k == 0) {
                // Count elements appearing more than once
                if (val > 1) count++;
            } else {
                // Check if num + k exists
                if (freq.count(num + k)) count++;
            }
        }

        return count;
    }
};
