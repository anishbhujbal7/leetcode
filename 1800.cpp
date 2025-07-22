class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int left = 0;
        int maxSum = 0;
        int maxNum =0;
        int currSum = nums[0];
        if(nums.size()==1) return nums[0];
        for(int right = 1; right<nums.size();right++){
           maxNum =max(maxNum,max(nums[right],nums[right-1]));
           if(nums[right-1]<nums[right]){
              currSum+=nums[right];
              maxSum = max(maxSum,currSum);
           }
           else{
            left = right;
            currSum  = nums[right];
           }
        }
        return max(maxSum, maxNum);
    }
};
