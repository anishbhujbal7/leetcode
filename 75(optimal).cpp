class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0;
        int n = nums.size();
        int mid = 0;
        int high = n - 1;
        while (mid <= high) {
            if (nums[mid] == 0) {
                std::swap(nums[mid], nums[low]);
                low++;
                mid++;
            }
            else if (nums[mid] == 1)
                mid++;
            else {
                std::swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};
