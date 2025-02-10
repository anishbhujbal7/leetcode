class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cm=nums[0];
        int gm=nums[0];
        for(int i=1;i<nums.size(); i++){
            cm=max(nums[i], nums[i]+cm);
            if(cm>gm){
                gm=cm;
            }
        }
        return gm;
    }
};
