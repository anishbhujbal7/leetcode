class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        int sumA=0;
        int sumB=0;
        for(int i=0;i<aliceSizes.size();i++){
            sumA=sumA+aliceSizes[i];
        }
        for(int i=0; i<bobSizes.size();i++){
            sumB=sumB+bobSizes[i];
        }
        int target=(sumA-sumB)/2;
        for(int i=0;i<aliceSizes.size();i++){
            for (int j=0;j<bobSizes.size();j++){
                if(target==(aliceSizes[i]-bobSizes[j])) return {aliceSizes[i],bobSizes[j]};
            }
        }
        return {};
    }
};
