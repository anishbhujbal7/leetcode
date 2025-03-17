class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int localMaxi = 0;
        int globalMaxi = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                localMaxi++;
                globalMaxi = max(globalMaxi, localMaxi);  // Update max here itself
            } else {
                localMaxi = 0;  // Reset local count on encountering 0
            }
        }

        return globalMaxi;
    }
};
