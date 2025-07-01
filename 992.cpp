class Solution {
public:

    int atmostElements(vector<int>& nums, int k){
        unordered_map<int , int> uniqueMap;
        int left=0;
        int count=0;
        int n = nums.size();
        for (int right =0;right<n;right++){
            uniqueMap[nums[right]]++;
            while(uniqueMap.size()>k){
                uniqueMap[nums[left]]--;
                if(uniqueMap[nums[left]]==0) uniqueMap.erase(nums[left]);
                left++;
            }
             count+=(right-left)+1;
        }
        return count;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atmostElements(nums, k) - atmostElements(nums,k-1);
    }
};
