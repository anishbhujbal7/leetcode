class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> diffArray(n + 1, 0); // +1 for safe right+1 access

        // Build difference array
        for (auto &q : queries) {
            int left = q[0];
            int right = q[1];
            diffArray[left] += 1;
            diffArray[right + 1] -= 1;
        }

        // Check using running prefix sum
        int curr = 0;
        for (int i = 0; i < n; i++) {
            curr += diffArray[i]; // total decrements applied so far
            if (curr < nums[i])   // not enough to zero this element
                return false;
        }
        return true;
    }
};


class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> diffArray(n+1);
        for(auto num:queries){
            int left = num[0];
            int right = num[1];
            diffArray[left]+=1;
            diffArray[right+1]-=1;
        }
        vector<int> prefixSum(n);
        prefixSum[0]=diffArray[0];
        if( prefixSum[0]<nums[0]) return false;
        for(int i = 1; i<n; i++){
            prefixSum[i] = prefixSum[i-1]+diffArray[i];
            if(prefixSum[i]<nums[i]) return false; 
        }
        return true;
    }
};
