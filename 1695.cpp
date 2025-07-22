class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int,int> map;
        int left =0;
        int sum=0;
        int maxSum= 0;
        int n = nums.size();
        for(int right = 0; right<n;right++){
            if(map.count(nums[right])){
                int ind = map[nums[right]];
                while(left!=ind){
                    map.erase(nums[left]);
                    sum-=nums[left];
                    left++;
                }
                map.erase(nums[left]);
                sum-=nums[left];
                left++;
            }
            map[nums[right]]=right;
            sum+=nums[right];
            maxSum = max(maxSum,sum);
        }
        return maxSum;
    }
};
