class Solution {
public:
    int findLHS(vector<int>& nums) {
      int n =  nums.size();
      sort(nums.begin(),nums.end());
      int left=0;
      int maxLen=0;
      for(int right=1;right<n;right++){
        while(nums[right]-nums[left]>1){
            left++;
        }
        if(nums[right]-nums[left]==1) maxLen=max(maxLen,right-left+1);
      }
      return maxLen;  
    }
};
