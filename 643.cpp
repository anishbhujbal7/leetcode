class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double maxAvg = INT_MIN;
        double currAvg = 0;
        int left = 0;
        int n = nums.size();
        for (int right = 0; right < n; right++) {
            while (right - left + 1 > k) {
                currAvg -= nums[left];
                left++;
            }
            currAvg += nums[right];
            if (right - left + 1 == k) {
                maxAvg = max(maxAvg, currAvg / k);
            }
        }
        return maxAvg;
    }
};
