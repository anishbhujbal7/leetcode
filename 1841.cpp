class Solution {
public:

    int rev(int num) {
        int revNum = 0;
        while (num > 0) {
            int digit = num % 10;           // Get last digit
            revNum = revNum * 10 + digit;   // Append digit
            num = num / 10;                 // Remove last digit
        }
        return revNum;
    }
    int countNicePairs(vector<int>& nums) {
        unordered_map<int,int> map;
        int n = nums.size();
        for(int i =0;i<n;i++){
            map[nums[i]-rev(nums[i])]++;
        }
        long long count  =0;
        int mod = 1e9 + 7;
        for (auto pair:map){
            long long freq= pair.second;
            count = (count + (freq*(freq-1)/2)%mod)%mod;
        }
        return (int)count;
    }
};
