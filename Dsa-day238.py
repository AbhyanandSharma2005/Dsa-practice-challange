class Solution:
    def minNumberOfSeconds(self, mountainHeight: int, workerTimes: List[int]) -> int:
        minW = workerTimes[0]
        maxW = minW
        minIdx = 0
        
        for i in range(1, len(workerTimes)):
            w = workerTimes[i]
            if w < minW:
                minW = w
                minIdx = i
            elif w > maxW:
                maxW = w
                
        if minIdx != 0:
            workerTimes[minIdx] = workerTimes[0]
            workerTimes[0] = minW
            
        length = len(workerTimes)
        ceilH = (mountainHeight + length - 1) // length
        tasks = ceilH * (ceilH + 1) // 2
        l = tasks * minW
        r = tasks * maxW
        ans = r
        
        while l <= r:
            mid = l + ((r - l) >> 1)
            mid2 = mid << 1
            total_sum = 0
            
            for i in range(length):
                val = mid2 // workerTimes[i]
                if val >= 2:
                    x = math.isqrt(val)
                    if x * (x + 1) > val:
                        x -= 1
                    total_sum += x
                    if total_sum >= mountainHeight:
                        break
                        
            if total_sum >= mountainHeight:
                ans = mid
                r = mid - 1
            else:
                l = mid + 1
                
        return ans