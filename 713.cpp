class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int cnt = 0;
        if (k <= 1)
            return 0;
        double currProduct = 1;
        int n = nums.size();
        int left = 0;
        for (int right = 0; right < n; right++) {
            currProduct *= nums[right];
            while (currProduct >= k) {
                currProduct = currProduct / nums[left];
                left++;
            }

            cnt += (right - left + 1);
        }
        return cnt;
    }
};
