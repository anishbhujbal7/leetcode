class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int ind=intervals.size();
        for(int i =0;i<intervals.size();i++){
            if(intervals[i][0]>=newInterval[0]){
                ind=i;
                break;
            }
        }
        intervals.insert(intervals.begin()+ind,newInterval);
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        for(int i=1;i<intervals.size();i++){
            vector<int> last=ans.back();
            if(last[1]>=intervals[i][0]){
                last[1]=max(last[1],intervals[i][1]);
                ans.back()=last;
            }
            else{
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};
