class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashTable;
        
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];  
            
            if (hashTable.count(complement)) {
                return {hashTable[complement], i};
            }
            
            hashTable[nums[i]] = i;
        }
        
        return {}; // This line should never be reached as per the problem's constraint.
    }
};
