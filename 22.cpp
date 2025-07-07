class Solution {
public:

    void findPara(string str,int open, int close, vector<string>& ans, int n){
        if (str.size()==2*n){
            ans.push_back(str);
            return;
        }
        if(open<n){
            findPara(str+'(',open+1,close,ans,n);
        }
        if(close<open){
            findPara(str+')', open,close+1,ans,n);
        }
    }

    vector<string> generateParenthesis(int n) {
       int open=0;
       int close=0;
       string str="";
       vector<string> ans;
       findPara(str,open,close,ans, n);
       return ans; 
    }
};
