class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> right(n);
        vector<int> left(n);
        int count =0;
        for(int i = 1;i<n;i++){
            if(nums[i-1]>=nums[i]){
                count++;
            }
            else{
                count = 0;
            }
            left[i] = count;
        }
        count  = 0;
        for(int i = n-2; i>=0;i--){
            if(nums[i+1]>=nums[i]) count++;
            else count = 0;
            right[i] = count;
        }
        vector<int> ans;
        for(int i = k;i<n-k;i++){
            if(left[i-1]>=k-1&&right[i+1]>=k-1) ans.push_back(i);
        }
        return ans;
    }
};
