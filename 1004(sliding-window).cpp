class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
      int n = nums.size();
      int oneCount = 0;
      int left = 0;
      int maxLen = 0;
      for(int right = 0; right<n; right++){
        if(nums[right]==1) oneCount++;
        while(right-left+1-oneCount>k){
            if(nums[left]==1) oneCount--;
            left++;
        }
        maxLen = max(maxLen,right-left+1);
      }
      return maxLen;  
    }
};
