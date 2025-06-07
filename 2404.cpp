class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int,int> hashMap;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if (nums[i]%2==0) hashMap[nums[i]]++;
        }
        int currMax=-1;
        int maxCnt=0;
        for(auto i:hashMap){
            if (i.second>maxCnt) {
                currMax=i.first;
                maxCnt=i.second;
            }
            else if (i.second==maxCnt){
                if(i.first<currMax) currMax=i.first;
            }
        }
        return currMax;
    }
};
