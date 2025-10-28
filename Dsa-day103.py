class Solution:
    def countValidSelections(self, nums: List[int]) -> int:
        def simulate(start, dir):
            arr = nums[:]
            curr = start
            n = len(arr)
            while 0 <= curr < n:
                if arr[curr] == 0:
                    curr += dir
                else:
                    arr[curr] -= 1
                    dir *= -1
                    curr += dir
            return all(x == 0 for x in arr)

        res = 0
        for i in range(len(nums)):
            if nums[i] == 0:
                if simulate(i, 1):
                    res += 1
                if simulate(i, -1):
                    res += 1
        return res
