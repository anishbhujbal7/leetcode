class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n =nums.size();
        unordered_map<int,int> prefixReminderCount;
        int currSum=0;
        int count=0;
        prefixReminderCount[0]=1;     // empty prefix has remainder 0
        for(int i =0;i<n;i++){
           currSum+=nums[i];
           int reminder=currSum%k;
           if (reminder<0) reminder+=k;  // if reminder is negative add the divisor in the reminder  
           if(prefixReminderCount.find(reminder)!=prefixReminderCount.end()){
            count+=prefixReminderCount[reminder];
           }
           prefixReminderCount[reminder]++;
        }
        return count;
    }
};
