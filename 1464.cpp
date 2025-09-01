class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max1 = 0;
        int maxInd = -1;
        int max2 = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > max1) {
                max1 = nums[i];
                maxInd = i;
            }
        }

        for (int i = 0; i < nums.size(); i++) {
            if (i == maxInd)
                continue;
            max2 = max(max2, nums[i]);
        }
        return ((max1 - 1) * (max2 - 1));
    }
};
