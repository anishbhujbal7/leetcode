class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        map<int, int> map;
        int n= nums.size();
        int left=0;
        vector<int> res;
        for(int right= 0;right<n;right++){
            map[nums[right]]++;
            while(right-left+1>k){
                map[nums[left]]--;
                if(map[nums[left]]==0) map.erase(nums[left]);
                left++;
            }

            if(right-left+1==k){
                int temp=map.rbegin()->first;
                res.push_back(temp);
            }
        }
        return res;
    } 
};
