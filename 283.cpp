class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n= nums.size();
        
        int j=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                j=i;
                while(nums[j]==0 &&j<n-1) j++;
                swap(nums[i],nums[j]);
                
            }
        }

    }
};
