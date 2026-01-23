class Solution:
    def minimumPairRemoval(self, nums: List[int]) -> int:
        n = len(nums)
        L, R = list(range(-1, n - 1)), list(range(1, n + 1))
        
        pairs = []
        descents = 0
        for i in range(n - 1):
            if nums[i] > nums[i + 1]: descents += 1
            pairs.append((nums[i] + nums[i + 1], i, i + 1))
        heapq.heapify(pairs)

        answer = 0
        while descents > 0:
            pair_sum, left, right = heapq.heappop(pairs)
            if R[left] != right or nums[left] + nums[right] != pair_sum:
                continue

            R[left] = -1  
            L[right] = L[left]

            descents -= (nums[left] > nums[right])

            if (prev := L[left]) != -1:
                descents += (nums[prev] > pair_sum) - (nums[prev] > nums[left])
                R[prev] = right
                heapq.heappush(pairs, (nums[prev] + pair_sum, prev, right))

            if (nxt := R[right]) != n:
                descents += (pair_sum > nums[nxt]) - (nums[right] > nums[nxt])
                L[nxt] = right
                heapq.heappush(pairs, (pair_sum + nums[nxt], right, nxt))

            nums[right] = pair_sum
            answer += 1
            
        return answer