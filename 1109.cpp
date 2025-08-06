class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> ans(n);
        
        for(auto i:bookings){
            int left = i[0];
            int right = i[1];
            int sum  = i[2];
            for(int j = left-1; j<right;++j){
                ans[j] +=sum;
            }
        }
        return ans;
    }
};
