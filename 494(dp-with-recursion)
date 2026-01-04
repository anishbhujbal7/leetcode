// here the string part of the map represents the current indesx  i and the the sum till that index and the integer part represents the number of possible expressions whose sum equals target 

// the solve function retrun the number of possible expressions the equal to target if we choose to add or sub thart perticular number 

// so at the end vwe do dp[key] = add + sub as we want all the possible expressios  that  can be for med if we add or sub the current number 


class Solution {
public:

    int solve(int i, int currSum, vector<int>& nums, unordered_map<string, int>& dp, int target){
        if(i == nums.size()){
            return (currSum == target) ? 1 : 0;
        }
        string key = to_string(i) + "," + to_string(currSum);
        if(dp.count(key)) return dp[key];

        int add = solve(i+1, currSum + nums[i], nums, dp, target);
        int sub = solve(i+1, currSum - nums[i], nums, dp, target);

        return dp[key] = add + sub;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
      unordered_map<string, int>dp;
      int possibleExpressions = solve(0, 0, nums, dp, target);
      return possibleExpressions;    
    }
};
