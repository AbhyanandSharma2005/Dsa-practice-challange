class Solution:
    def minOperations(self, nums: List[int]) -> int:
        output = 0
        stack = []
        for num in nums:
            while stack and stack[-1] > num:
                output += 1
                stack.pop()
            if num and (not stack or stack[-1] != num):
                stack.append(num)
        return output + len(stack)
