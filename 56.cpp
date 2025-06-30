class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> merged;
        merged.push_back(intervals[0]);
        for(int i=0;i<intervals.size();i++){
            vector<int> last=merged.back();
            if(last[1]>=intervals[i][0]){
                last[1]=max(last[1],intervals[i][1]);
                merged.back()=last;
            }
            else{
                merged.push_back(intervals[i]);
            }
        }
        return merged;
    }
};
