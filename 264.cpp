class Solution {
public:

    int findUglyNo(vector<int> &dp,int n, int i,int p2, int p3, int p5){
        if(i==n) return dp[n-1];
        int two=dp[p2]*2;
        int three=dp[p3]*3;
        int five=dp[p5]*5;

        dp[i]=min(two,min(three,five));

        dp[i]==two?p2++:p2;
        dp[i]==three?p3++:p3;
        dp[i]==five?p5++:p5;

        return findUglyNo(dp, n, i+1,p2,p3,p5);
    }

    int nthUglyNumber(int n) {
        if (n==1) return 1;
        vector<int> dp(n);
        dp[0]=1;
        return findUglyNo(dp,n,1,0,0,0);
    }
};
