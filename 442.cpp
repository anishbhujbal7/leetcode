class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        for(int num : nums){
            
            int index= abs(num)-1;
            if(nums[index]<0) ans.push_back(abs(num));
            nums[index]=nums[index]*-1;
            
        }
        return ans;
    }
};
