class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans=nums[0];
        int cmax=1, cmin=1;
        for(int i=0;i<nums.size();i++){
            int temp= cmax*nums[i];
            cmax=max(max(cmax*nums[i],cmin*nums[i]),nums[i]);
            cmin=min(min(temp,cmin*nums[i]),nums[i]);
            ans=max(ans, cmax);
        }
        return ans;
    }
};
