class Solution:
    def arrayRankTransform(self, arr: list[int]) -> list[int]:
        ranks = {}
        rank = 1
        for num in sorted(arr):
            if num not in ranks:
                ranks[num] = rank
                rank += 1
        return [ranks[num] for num in arr]