class Solution:
    def maxSumTrionic(self, nums: List[int]) -> int:
        out = float('-inf')
        n = len(nums)
        i = 0

        while i < n-1:
            start = i
            
            while i < n-1 and nums[i] < nums[i+1]:
                i += 1
            p = i
            if p == start:
                i += 1
                continue

            while i < n-1 and nums[i] > nums[i+1]:
                i += 1
            q = i

            if q == p:
                i = q
                continue


            while i < n-1 and nums[i] < nums[i+1]:
                i += 1
            end = i

            # start p q end
            if (p!=start) and (q!=p) and (end!=q):
                temp = sum(nums[p-1:q+1])

                max_sum, cur_sum = 0, 0
                for j in range(p-2, start-1, -1):
                    cur_sum += nums[j]
                    max_sum = max(cur_sum, max_sum)
                temp += max_sum

                max_sum, cur_sum = nums[q+1], nums[q+1]
                for j in range(q+2, end+1):
                    cur_sum += nums[j]
                    max_sum = max(cur_sum, max_sum)
                temp += max_sum

                out = max(out, temp)
                i = q
        
        return out