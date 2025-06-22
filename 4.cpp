class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        int total = m + n;
        int midIndex = total / 2;

        int p1 = 0, p2 = 0;
        int curr = 0, prev = 0;

        for (int i = 0; i <= midIndex; i++) {
            prev = curr;
            if (p1 < m && (p2 >= n || nums1[p1] <= nums2[p2])) {
                curr = nums1[p1++];
            } else {
                curr = nums2[p2++];
            }
        }

        if (total % 2 == 0) {
            return (prev + curr) / 2.0;
        } else {
            return curr;
        }
    }
};
