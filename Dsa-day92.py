class Solution:
    def maxPartitionsAfterOperations(self, s: str, k: int) -> int:
        n = len(s)
        prefix = [[0, 0, set()] for _ in range(n)]
        suffix = [[0, 0, set()] for _ in range(n)]

        partitions = 0
        last_partition_start = 0
        char_set = set()
        for i, ch in enumerate(s):
            prefix[i] = [partitions, last_partition_start, char_set.copy()]
            char_set.add(ch)
            if len(char_set) > k:
                partitions += 1
                last_partition_start = i
                char_set = {ch}

        partitions = 0
        last_partition_start = n - 1
        char_set = set()
        for i in range(n - 1, -1, -1):
            suffix[i] = [partitions, last_partition_start, char_set.copy()]
            ch = s[i]
            char_set.add(ch)
            if len(char_set) > k:
                partitions += 1
                last_partition_start = i
                char_set = {ch}

        ans = 0
        for i in range(n):
            merged = prefix[i][2].union(suffix[i][2])
            if len(merged) < k or k >= 26:
                contribution = 1
            elif len(prefix[i][2]) == k and len(suffix[i][2]) == k and len(merged) < 26:
                contribution = 3
            else:
                contribution = 2
            ans = max(ans, prefix[i][0] + suffix[i][0] + contribution)
        return ans
