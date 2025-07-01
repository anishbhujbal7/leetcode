int longestSubarrayDivByK(vector<int>& nums, int k) {
    unordered_map<int, int> remainderIndex;
    remainderIndex[0] = -1; // To handle subarrays starting from index 0

    int currSum = 0, maxLength = 0;

    for (int i = 0; i < nums.size(); i++) {
        currSum += nums[i];
        int rem = currSum % k;
        if (rem < 0) rem += k;

        if (remainderIndex.find(rem) != remainderIndex.end()) {
            maxLength = max(maxLength, i - remainderIndex[rem]);
        } else {
            remainderIndex[rem] = i;  // store first occurrence of this remainder
        }
    }

    return maxLength;
}
