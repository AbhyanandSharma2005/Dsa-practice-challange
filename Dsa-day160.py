class Solution:
    def minimumBoxes(self, apple: List[int], capacity: List[int]) -> int:
        total = sum(apple)
        capacity.sort(reverse=True)
        s = 0
        for i in range(len(capacity)):
            s += capacity[i]
            if s >= total:
                return i + 1
        return len(capacity)