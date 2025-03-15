class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n= nums.size();
        int d=k%n;
        vector<int> temp(d);
        int j=0;
        for(int i=n-d;i<n;i++){
           temp[j]=nums[i];
           j++;
        }
        for (int i = n-d-1;i>=0;i--){
            nums[i+d]=nums[i];
        }
        for (int i=0;i<d;i++){
            nums[i]=temp[i];
        }
        
    }
};
