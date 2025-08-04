class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
      int totalProduct = 1;
      int n = nums.size();
      bool isZero = false;
      int zeroCnt =0;
      for(int i =0;i<n;i++){
        if(nums[i]==0){
            isZero = true;
            zeroCnt++;
            continue;
        }
        totalProduct *= nums[i]; 
      }
      vector<int> res;
      for(int i = 0;i<n;i++){
        if(zeroCnt>=2) res.push_back(0);
        else{
            if(nums[i]==0&&zeroCnt==1) res.push_back(totalProduct);
            else if(nums[i]!=0&&zeroCnt==1) res.push_back(0);
            else{
                res.push_back(totalProduct/nums[i]);
            }
        }
      }
      return res;  
    }
};
