class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        int m = nums.size();
        int totalSubsets = 1 << m;
        sort(nums.begin(), nums.end());

        set<vector<int>> ans;

        for (int number = 0; number < totalSubsets; number++) {
            vector<int> current;
            for (int i = 0; i < m; i++) {
                if ((number >> i) & 1)
                    current.push_back(nums[i]);
            }
            ans.insert(current);
        }
        return vector<vector<int>>(ans.begin(), ans.end());
    }
};
