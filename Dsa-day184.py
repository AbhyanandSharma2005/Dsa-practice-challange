class Solution:
    def largestSquareArea(self, bottomLeft: List[List[int]], topRight: List[List[int]]) -> int:
        n = len(bottomLeft)
        max_side = 0
        
        for i in range(n):
            for j in range(i + 1, n):
                # intersection left   = max of lefts
                left   = max(bottomLeft[i][0], bottomLeft[j][0])
                # intersection bottom = max of bottoms
                bottom = max(bottomLeft[i][1], bottomLeft[j][1])
                # intersection right  = min of rights
                right  = min(topRight[i][0],   topRight[j][0])
                # intersection top    = min of tops
                top    = min(topRight[i][1],   topRight[j][1])
                
                # if intersection exists
                if left < right and bottom < top:
                    side = min(right - left, top - bottom)
                    max_side = max(max_side, side)
        
        return max_side * max_side