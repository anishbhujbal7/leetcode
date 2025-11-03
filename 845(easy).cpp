class Solution {
public:
    void leftSide(vector<int>& arr, vector<int>& leftArr, int n) {
        int count = 0;
        for (int i = 1; i < n; i++) {
            if (arr[i] > arr[i - 1])
                count++;
            else
                count = 0;
            leftArr[i] = count;
        }
    }

    void rightSide(vector<int>& arr, vector<int>& rightArr, int n) {
        int count = 0;
        for (int i = n - 2; i >= 0; i--) {
            if (arr[i] > arr[i + 1])
                count++;
            else
                count = 0;
            rightArr[i] = count;
        }
    }

    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        vector<int> leftArr(n);
        vector<int> rightArr(n);
        leftSide(arr, leftArr, n);
        rightSide(arr, rightArr, n);

        int maxLen = 0;
        for (int i = 0; i < n; i++) {
            if (leftArr[i] > 0 && rightArr[i] > 0)
                maxLen = max(maxLen, leftArr[i] + rightArr[i] + 1);
        }
        return maxLen;
    }
};
