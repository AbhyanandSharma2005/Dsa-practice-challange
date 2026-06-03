class Solution:
    def earliestFinishTime(self, landStartTime: list[int], landDuration: list[int], waterStartTime: list[int], waterDuration: list[int]) -> int:
        def getMinFinishTime(start1: list[int], dur1: list[int], start2: list[int], dur2: list[int]) -> int:
            min_finish1 = min(s + d for s, d in zip(start1, dur1))
            
            total_min = float('inf')
            for s, d in zip(start2, dur2):
                current_finish = max(min_finish1, s) + d
                if current_finish < total_min:
                    total_min = current_finish
                    
            return total_min

        return min(
            getMinFinishTime(landStartTime, landDuration, waterStartTime, waterDuration),
            getMinFinishTime(waterStartTime, waterDuration, landStartTime, landDuration)
        )