class Solution:
    def minimumCost(self, nums: List[int], k: int, dist: int) -> int:
        target = k - 1
        sl = SortedList(nums[1 : dist + 2])
        current_sum = sum(sl[:target])
        min_sum = current_sum

        for i in range(1, len(nums) - dist - 1):
            out_v = nums[i]
            in_v = nums[i + dist + 1]
            
            sl.add(in_v)
            if in_v < sl[target]:
                current_sum += in_v - sl[target]
            
            if out_v < sl[target]:
                current_sum -= out_v
                current_sum += sl[target]
            
            sl.remove(out_v)
            min_sum = min(min_sum, current_sum)
            
        return nums[0] + min_sum