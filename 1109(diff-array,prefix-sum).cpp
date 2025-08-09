class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> ans(n);
        vector<int> diffArray(n+1);
        
        for(auto i:bookings){
            int left = i[0]-1;
            int right = i[1]-1;
            int sum  = i[2];
            diffArray[left] += sum;
            diffArray[right+1] -= sum;
        }
        ans[0]=diffArray[0];
        for(int i = 1; i<n; i++){
            ans[i] = ans[i-1]+diffArray[i];
        }

        return ans;
    }
};
