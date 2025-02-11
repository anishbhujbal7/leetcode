class Solution(object):
    def maxProduct(self, nums):
        ans = nums[0]  # Initialize with the first element of nums
        cmax, cmin = 1, 1  # Initializing cmax and cmin

        # Start from the first element (nums[0])
        for i in nums:
            temp = i * cmax  # Store the product of current max and num
            cmax = max(i * cmax, i * cmin, i)  # Update current max
            cmin = min(temp, i * cmin, i)  # Update current min
            ans = max(ans, cmax)  # Update the result with the max value

        return ans  # Return the final answer
