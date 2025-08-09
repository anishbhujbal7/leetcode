class Solution {
public:
    bool canZero(vector<int>& nums, vector<vector<int>>& queries, int k) {
    int n = nums.size();
    vector<long long> diff(n + 1, 0); // difference array (long long to avoid overflow)

    // Apply first k queries in difference array form
    for (int i = 0; i < k; i++) {
        int l = queries[i][0];
        int r = queries[i][1];
        int val = queries[i][2];
        diff[l] += val;
        if (r + 1 < n) diff[r + 1] -= val;
    }

    // Prefix sum to get total budget for each index
    long long curr = 0;
    for (int i = 0; i < n; i++) {
        curr += diff[i];
        if (curr < nums[i]) return false; // Not enough budget to make nums[i] zero
    }
    return true;
}

    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int left = 0, right = queries.size(), ans = -1;

        while (left <= right) {
            int mid = (left + right) / 2;
            if (canZero(nums, queries, mid)) {
                ans = mid;
                right = mid - 1; // try smaller k
            } else {
                left = mid + 1; // need more queries
            }
        }
        return ans;
    }
};
