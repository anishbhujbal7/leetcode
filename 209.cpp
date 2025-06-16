class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int minSize = INT_MAX;
        int left= 0;
        int currSum=0;
        for(int right=0;right<n;right++){
            currSum=currSum+nums[right];
           
            while(currSum>=target){
                currSum-=nums[left];
                minSize=min(minSize,right-left+1);
                left++;
            }
        }
        return minSize==INT_MAX ? 0:minSize;
    }
};
