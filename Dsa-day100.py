class Solution:
    def totalMoney(self, n: int) -> int:
        weeks, days = divmod(n, 7)
        total = 28 * weeks + 7 * (weeks * (weeks - 1)) // 2
        total += days * (2 * weeks + days + 1) // 2
        return total
