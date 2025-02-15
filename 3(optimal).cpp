class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> hashTable;
        int max_len=0;
        int left=0;
        for(int right=0;right<s.length();right++){
            if(hashTable.find(s[right])!=hashTable.end()&&hashTable[s[right]]>=left){
                left=hashTable[s[right]]+1;
            }
            hashTable[s[right]]=right;
            max_len=max(max_len,right-left+1);
        }
        return max_len;
    }
};
