class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end()); 
        vector<vector<int>> ans;

        for (int i = 0; i < nums.size() - 2; i++) { // At least 3 elements needed
            if (i > 0 && nums[i] == nums[i - 1]) continue; // Skip duplicate values for i

            int j = i + 1, k = nums.size() - 1;
            
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];

                if (sum == 0) {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    
                    // Skip duplicate values for j
                    while (j < k && nums[j] == nums[j + 1]) j++;
                    // Skip duplicate values for k
                    while (j < k && nums[k] == nums[k - 1]) k--;

                    // Move to next distinct numbers
                    j++;
                    k--;
                } 
                else if (sum < 0) {
                    j++; // Increase sum by moving `j` forward
                } 
                else {
                    k--; // Decrease sum by moving `k` backward
                }
            }
        }

        return ans;
    }
};
