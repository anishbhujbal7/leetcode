class Solution {
public:

    int ways(int i, int n, vector<int>& dp,string s){
        if(i==n) return 1;
        if(s[i]=='0') return  0;
        if(dp[i]!=-1) return dp[i];
        int option1 = ways(i+1,n,dp,s);
        int twoDigit=stoi(s.substr(i,2));
        if(twoDigit>=10&&twoDigit<=26){
            option1 += ways(i+2,n,dp,s);
        }
        return dp[i] = option1;
    }

    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n,-1);
        return ways (0,n,dp,s);
    }
};
