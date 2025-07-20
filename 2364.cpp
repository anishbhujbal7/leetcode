class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n =nums.size();
        unordered_map<long long,long long> map;
        for(auto i =0;i<n;i++){
          long long diff=(long long) nums[i]-i;
          map[diff]++;
        }
        long long goodPairs=0;
        for(auto i: map){
            goodPairs+= i.second*(i.second-1)/2;
        }
        long long totalPairs=(long long)n*(n-1)/2;
        return totalPairs-goodPairs;
    }
};
