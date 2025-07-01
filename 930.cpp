// at each index we ask How many times has currSum - goal appeared before?
// then we add that number to the count;

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int , int > prefixCount;
        prefixCount[0]=1;
        int currSum=0;
        int count= 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            currSum+=nums[i];
            if(prefixCount.find(currSum-goal)!=prefixCount.end()){
                count+=prefixCount[currSum-goal];
            }
            prefixCount[currSum]++;
        }
        return count;
    }
};
