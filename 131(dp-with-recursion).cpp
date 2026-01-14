class Solution {
public:

    vector<vector<string>> allPartitions(int start, vector<vector<bool>>& dp, unordered_map<int,                    vector<vector<string>>>& memo, string& s){
        if(memo.count(start)) return memo[start];
        int n = s.size();
        vector<vector<string>> result;
        // base case : reached the end
        if(start == n){
            result.push_back({});
            return memo[start] = result;
        }
        for(int end = start; end < n; end++){
            if(dp[start][end]){
                string curr = s.substr(start, end - start +1);
                // calculate the rest of the palindromes strating at index start
                auto rest = allPartitions(end+1, dp, memo, s);
                for(auto& partition : rest){
                    vector<string> temp;
                    // fist add the current partition the temp
                    temp.push_back(curr);
                    // then  add the rest of the partiton to the temp
                    temp.insert(temp.end(), partition.begin(), partition.end());
                    result.push_back(temp);
                }
            }
        }
        return memo[start] = result;
    }

    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        // dp[i][j] tells us if substr(i,j) is a palindrome or not
        for(int i = n-1; i>=0; i--){
            for(int j = 0; j<n; j++){
                if(s[i] == s[j] && (j-i<=2 || dp[i+1][j-1])){
                    // any string till length 2 is automatically a palindreome like aba, aa, aaa etc 
                    // here i the start of the susbsting and j is thr end of the substring and if everything between i and  j is a substring (i and j not  included) then if we add s[i] and s[j] to the start and end of the substring then the resulting substring will also be a pallindrome as s[i] == s[j]  
                    dp[i][j] = true;
                }
            }
            
        }
        unordered_map<int,vector<vector<string>>> memo;
        return allPartitions(0, dp, memo, s);
    }
};
