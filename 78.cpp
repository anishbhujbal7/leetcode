class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        int totalSubsets=1<<n;
        vector<vector<int>> ans;

        for (int number=0;number<totalSubsets;number++){
            vector<int> current;
            for(int i=0;i<n;i++){
                if((number>>i)&1) current.push_back(nums[i]);
            }
            ans.push_back(current);
        }
        return ans;
    }
};
