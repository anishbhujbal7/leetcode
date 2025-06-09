class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> hashMap;
        int n=nums.size();
        vector<int> res;
        for(int i=0;i<n;i++){
            hashMap[nums[i]]++;
        }
        vector<int> sortedVec;
        for(auto i:hashMap){
            sortedVec.push_back(i.second);
        }
        sort(sortedVec.begin(),sortedVec.end(), greater<int>());
        for(int i=0;i<sortedVec.size();i++){
            if(k==0) break;
            int target=sortedVec[i];
            for(auto pair:hashMap){
                if(pair.second==target){
                    res.push_back(pair.first);
                    hashMap[pair.first]=-1;
                    k--;
                }
            }
        }
        return res;
    }
};
