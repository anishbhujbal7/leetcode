class Solution(object):
    def characterReplacement(self, s, k):
        max_len=0
        max_count=0
        left=0
        charSet = defaultdict(int)
        for right in range(len(s)):
            c=s[right]
            charSet[c]+=1
            max_count=max(max_count,charSet[c])
            while (right-left+1)-max_count>k:      
                charSet[s[left]]-=1
                left+=1
            max_len=max(max_len,right-left+1)
        return max_len
        
