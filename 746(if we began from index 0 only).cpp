#include <vector>
using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        
        // Base case: If there's only one step, take it
        if (n == 1) return cost[0];

        // Initialize previous two steps
        int prev2 = cost[0];  // Cost to reach step 0
        int prev1 = cost[0] + cost[1];  // Cost to reach step 1 from step 0

        // Compute the minimum cost to reach each step
        for (int i = 2; i < n; i++) {  
            int curr = cost[i] + min(prev1, prev2);
            prev2 = prev1;
            prev1 = curr;
        } 

        // The answer is the cost to reach the last step
        return min(prev1,prev2);
    }
};
