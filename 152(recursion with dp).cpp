class Solution {
public:

    int productFinder(int i,vector<int> &nums,vector<int> &maxdp,vector<int> &mindp,int &result){
        if(i==0){
            maxdp[i]=mindp[i]=nums[i];
            result=max(result,maxdp[i]);
            return maxdp[i];
        }
        if(maxdp[i]!=INT_MIN) return maxdp[i];
        productFinder(i-1,nums, maxdp,mindp,result);
        int maxPrev=maxdp[i-1];
        int minPrev=mindp[i-1];
        int option1=nums[i];
        int option2=nums[i]*minPrev;
        int option3=nums[i]*maxPrev;
        maxdp[i]=max({option1,option2,option3});
        mindp[i]=min({option1,option2,option3});
       
        result=max(result,maxdp[i]);
        return maxdp[i];
    }
    int maxProduct(vector<int>& nums) {
       int n=nums.size();
       vector<int> maxdp(n,INT_MIN), mindp(n,INT_MIN);
       int result=INT_MIN;
       int nothing= productFinder(n-1, nums, maxdp,mindp,result); 
       return result;
    }
};
