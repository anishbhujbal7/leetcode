class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int left = 0;
        int maxLen = 1;
        for(int right = 1; right<nums.size();right++){
           if(nums[right-1]<nums[right]){
            maxLen = max(maxLen, right-left+1);
           }
           else{
            left=right;
           }
        }
        return maxLen;
    }
};
