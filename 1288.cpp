class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](const vector<int> &a, const vector<int>& b){
            if(a[0]!=b[0]) return a[0]<b[0];
            return a[1]>b[1];
        });
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        for(int i =1;i<intervals.size();i++){
            vector<int> last=ans.back();
            if(last[1]>=intervals[i][1]) continue;
            else{
                ans.push_back(intervals[i]);
                }
        }
        return ans.size();
    }
};
