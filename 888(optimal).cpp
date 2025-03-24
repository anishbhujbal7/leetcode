class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        int sumA = 0;
        int sumB = 0;
        for (int i = 0; i < aliceSizes.size(); i++) {
            sumA = sumA + aliceSizes[i];
        }
        for (int i = 0; i < bobSizes.size(); i++) {
            sumB = sumB + bobSizes[i];
        }
        int target = (sumA - sumB) / 2;
        unordered_set<int> bobSet(bobSizes.begin(), bobSizes.end());
        for (int i = 0; i < aliceSizes.size(); i++) {
            if (bobSet.find(aliceSizes[i] - target) != bobSet.end()) {
                return {aliceSizes[i], aliceSizes[i] - target};
            }
        }
        return {};
    }
};
