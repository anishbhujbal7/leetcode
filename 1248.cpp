class Solution {
public:

    int atmost(int i,vector<int>& nums){
        int left = 0;
        int n = nums.size();
        int count = 0;
        int oddCount = 0;
        for(int right = 0; right<n; right++){
           
           if(nums[right]%2!=0) oddCount++;
           while(oddCount>i){
            if(nums[left]%2!=0) oddCount--;
            left++;
           }
           count+=(right-left+1);
        }
        return count;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return atmost(k,nums)-atmost(k-1,nums);
    }
};
