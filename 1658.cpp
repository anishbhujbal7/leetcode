class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int total =0;
        int n = nums.size();
        for (int i=0;i<n;i++) {
            total+=nums[i];
        }
        int target = total-x;
        int left =0;
        int len=-1;
        int currSum=0;
        for(int right =0;right<n;right++){
            currSum+=nums[right];
            while(currSum>target && right>=left){
                currSum-=nums[left];
                left++;
            }
            if (currSum==target) len=max(len, right-left+1);
        }
        return (len==-1)? -1: n-len;
    }
};
