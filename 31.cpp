class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int minNo =INT_MAX;
        int minIndex=-1;
        for (int i =nums.size()-2;i>=0;i--){
           if(nums[i]<nums[i+1]){
            minNo=nums[i];
            minIndex=i;
            break;
           }
           
        }
        if(minIndex==-1){
            sort(nums.begin(), nums.end());
            return;
        }
        int nextMin=INT_MAX;
        int ind=-1;
        for(int i=minIndex+1;i<nums.size();i++){
            int curr= nums[i];
            if(curr>minNo){
                if(curr<nextMin){
                    nextMin=curr;
                    ind =i;
                }
            }
        }
        swap(nums[minIndex],nums[ind]);
        sort(nums.begin()+minIndex+1,nums.end());
        return;
        
    }
};
