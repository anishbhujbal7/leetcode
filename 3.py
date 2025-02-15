class Solution(object):
    def lengthOfLongestSubstring(self, s):
       hashTable={}
       max_len=0
       left=0
       for right in range(len(s)):
            if s[right] in hashTable and hashTable[s[right]]>=left:
                left=hashTable[s[right]]+1
            hashTable[s[right]]=right
            max_len=max(max_len,right-left+1)
        
       return max_len

        
