class Solution(object):
    def maxArea(self, height):
       
        i,j=0,len(height)-1
        result=0
        while i<j:
            hmin=min(height[i],height[j])
            result=max(result,hmin*(j-i))
            if height[i]<height[j]:
                i+=1
            else:
                j-=1
        return result
