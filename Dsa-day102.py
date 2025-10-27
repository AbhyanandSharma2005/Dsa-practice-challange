class Solution:
    def numberOfBeams(self, bank: List[str]) -> int:
        prev = 0
        res = 0
        for row in bank:
            count = row.count('1')
            if count:
                res += prev * count
                prev = count
        return res
