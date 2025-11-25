class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0) return 0;
        queue<pair<int,int>> q;
        q.push({0,0});
        vector<bool> visited(amount+1,false);
        while(!q.empty()){
            int currSum = q.front().first;
            int steps = q.front().second;
            q.pop();
            for(auto coin : coins){
                int newSum = currSum + coin;
                if(newSum == amount) return steps+1;
                if(newSum < amount && !visited[newSum]){
                    q.push({newSum,steps+1});
                    visited[newSum] = true;
                }
            }
        }
        return -1;
    }
};
