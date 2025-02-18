class Solution {
public:
    int findMin(vector<int>& nums) {
       int high = nums.size() - 1;
       int low = 0;
       int result = nums[0];  // Initialize result to first element
      
       while (low < high) {
           int mid = low + (high - low) / 2;

           if (nums[mid] <= nums[high]) {
               result = min(result, nums[mid]);
               high = mid;  // Move high towards the minimum
           } 
           else {
               result = min(result, nums[low]);
               low = mid + 1;  // Move low towards the minimum
           }
       }
       return min(result, nums[low]);  // Ensure the final minimum is returned
    }
};
