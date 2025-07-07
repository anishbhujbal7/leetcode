class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
      unordered_map<int,int> map1;
      
      for(int i=0;i<nums1.size();i++){
        for(int j=0;j<nums2.size();j++){
            map1[nums1[i]+nums2[j]]++;
        }
      }
      int count=0;
      for(int i=0;i<nums3.size();i++){
        for(int j=0;j<nums4.size();j++){
            int target=-(nums3[i]+nums4[j]);
            if(map1.find(target)!=map1.end()){
                count=count+map1[target];
            }
        }
      }
      return count;
    } 
};
