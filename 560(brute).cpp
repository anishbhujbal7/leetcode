class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n= nums.size();
        int sumCnt=0;
        for(int i=0;i<n;i++){
            int currSum=0;
            for(int j=i;j<n;j++){
                currSum=urrSum+nums[j];
                if(currSum==k) sumCnt++;
            }

        }
        return sumCnt;
        
    }
};
