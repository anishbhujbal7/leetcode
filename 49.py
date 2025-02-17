class Solution(object):
    def groupAnagrams(self, strs):
        hashMap=defaultdict(list)
        for str in strs:
            sortedStr=str
            sortedStr=''.join(sorted(str))
            hashMap[sortedStr].append(str)
        return list(hashMap.values())
        
