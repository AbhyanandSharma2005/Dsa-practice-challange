import math

class Solution:
    def findKthBit(self, n, k):
        mid = 0  
        count = 0  

        while k > 2:

            aux = int(math.log(k) / math.log(2))

            if (1 << aux) == k and count == 0:
                return '1'

            if (1 << aux) == k:
                k = 2
                break
            else:
                mid = 1 << aux
                k = mid - (k - mid)

            count += 1

        if ((k < 2 and count % 2 == 0) or
            (k >= 2 and count % 2 == 1)):
            return '0'
        else:
            return '1'