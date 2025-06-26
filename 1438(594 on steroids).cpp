class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        int left = 0, maxLen = 0;
        map<int, int> freq;  // maintains sorted order of elements in window
        for(int right=0;right<n;right++){
            freq[nums[right]]++;
            while(freq.rbegin()->first-freq.begin()->first>limit){
                freq[nums[left]]--;
                if(freq[nums[left]]==0) freq.erase(nums[left]);
                left++;
            }
            maxLen=max(maxLen,right-left+1);
        }
        return maxLen;
    }
};
