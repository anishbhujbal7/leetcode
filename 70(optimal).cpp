// You are climbing a staircase. It takes n steps to reach the top.
// Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?


class Solution {
public:
    int climbStairs(int n) {
        int prev2= 1;
        int prev=2;
        int curr;
        if (n == 1) return 1;
        if (n == 2) return 2;
        for (int i=3;i<=n;i++){
            
            curr=prev+prev2;
            prev2=prev;
            prev=curr;
        }
        return prev;
        
    }
};
