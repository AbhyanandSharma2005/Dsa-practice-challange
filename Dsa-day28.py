class Solution:
    def largestGoodInteger(self, num: str) -> str:
        max_good = ""
        for i in range(len(num) - 2):
            if num[i] == num[i + 1] == num[i + 2]:
                sub = num[i:i + 3]
                if max_good == "" or sub > max_good:
                    max_good = sub
        return max_good
