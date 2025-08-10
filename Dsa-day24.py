class Solution:
    def reorderedPowerOf2(self, n: int) -> bool:
        sorted_n = ''.join(sorted(str(n)))
        for i in range(31):
            if ''.join(sorted(str(1 << i))) == sorted_n:
                return True
        return False
