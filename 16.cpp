class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n =nums.size();
        int ans=INT_MAX;
        int goSum=0;
        for(int i =0;i<n-2;i++){
            int left=i+1;
            int right=n-1;
            while(left!=right){
                int sum = nums[i]+nums[left]+nums[right];
                int something = abs(sum-target);
                if(something<ans){
                    goSum=sum;
                    ans=something;
                }
                if(sum>target) right--;
                else if(sum<target) left++;
                else return sum;
            }
        }
        return goSum;
    }
};
