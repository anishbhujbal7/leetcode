class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        vector<int> ans;
        int left = 0;
        int right = n - 1;
        int index = -1;

        // Binary search
        while (left <= right) {
            int mid = (left + right) / 2;
            if (arr[mid] == x) {
                index = mid;
                break;
            }
            else if (x > arr[mid]) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        if (index == -1) {
            if (x < arr[0]) {
                ans = vector<int>(arr.begin(), arr.begin() + k);
                return ans;
            }
            else if (x > arr[n - 1]) {
                ans = vector<int>(arr.end() - k, arr.end());
                return ans;
            }
            else {
                // insertion point is between right and left
                left = right;
                right = left + 1;
                int len = 0;

                while (left >= 0 && right < n && len < k) {
                    if (abs(arr[left] - x) <= abs(arr[right] - x)) {
                        left--;
                    } else {
                        right++;
                    }
                    len++;
                }
                while (len < k && left >= 0) { left--; len++; }
                while (len < k && right < n) { right++; len++; }

                ans = vector<int>(arr.begin() + left + 1, arr.begin() + right);
                return ans;
            }
        }

        // If x was found
        left = right = index;
        int len = 1;
        while (left >= 1 && right < n - 1 && len < k) {
            int a = arr[left - 1];
            int b = arr[right + 1];
            if (abs(a - x) < abs(b - x)) {
                left--;
            }
            else if (abs(a - x) > abs(b - x)) {
                right++;
            }
            else {
                left--;  // prefer left on tie
            }
            len++;
        }
        while (len < k && left > 0) { left--; len++; }
        while (len < k && right < n - 1) { right++; len++; }

        ans = vector<int>(arr.begin() + left, arr.begin() + right + 1);
        return ans;
    }
};
