class Solution {
public:
    int pivotIndex(vector<int>& nums) {
       int n = nums.size();
       vector<int> leftArray(n);
       vector<int> rightArray(n);
       int left = 0;
       int right =n-1;
       int i = 1;
       int j = n-2;
       int leftSum= 0;
       int rightSum = 0;
       while(left<n&&right>=0){
           leftSum += nums[left];
           leftArray[left] = leftSum;
           left++; 
           rightSum += nums[right];
           rightArray[right] = rightSum;
           right--;
       }
       for(int i =0; i<n; i++){
        if(leftArray[i]==rightArray[i]) return i;
       }
       return -1;
    }
};
