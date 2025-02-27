class Solution {
public:

    int f1(int ind1,vector<int>& nums1,vector<int>& dp1){
        
        if (ind1==0) return nums1[ind1];
        if (ind1<0) return 0;
        if (dp1[ind1]!=-1) return dp1[ind1];
        int pick= nums1[ind1]+f1(ind1-2,nums1,dp1);
        int notPick=0+f1(ind1-1,nums1,dp1);
        return dp1[ind1]=max(pick,notPick);
    }
    int f2(int ind2,vector<int>& nums2,vector<int>& dp2){
        
        if (ind2==0) return nums2[ind2];
        if (ind2<0) return 0;
        if (dp2[ind2]!=-1) return dp2[ind2];
        int pick= nums2[ind2]+f2(ind2-2,nums2,dp2);
        int notPick=0+f2(ind2-1,nums2,dp2);
        return dp2[ind2]=max(pick,notPick);
    }

    int rob(vector<int>& nums) {
        int n= nums.size();
        if (n == 1) return nums[0]; // Edge case: Only one house

        // Create separate copies of `nums` without modifying the original vector
        vector<int> nums1(nums.begin() + 1, nums.end()); // Exclude first house
        vector<int> nums2(nums.begin(), nums.end() - 1); // Exclude last house

        vector<int> dp1(n - 1, -1);
        vector<int> dp2(n - 1, -1);

        return max(f1(n - 2, nums1, dp1), f2(n - 2, nums2, dp2));
    }
};
