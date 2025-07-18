class Solution {
public:

    void findCombination(int n, int k,int start, vector<int>&curr, vector<vector<int>>& ans){
        if(curr.size()==k) {
            ans.push_back(curr);
            return;
        }
        for(int i=start;i<=n;i++){
            curr.push_back(i);
            findCombination(n,k,i+1,curr,ans);
            curr.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
      
       vector<vector<int>> ans;
       vector<int> curr;
       findCombination(n, k,1,curr,ans); 
       return ans; 
    }
};
