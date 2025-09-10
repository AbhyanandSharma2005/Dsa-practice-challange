from typing import List

class Solution:
    def minimumTeachings(self, n: int, languages: List[List[int]], friendships: List[List[int]]) -> int:
        lang_sets = [set(l) for l in languages]
        need_teach = set()
        for u, v in friendships:
            u -= 1; v -= 1
            if lang_sets[u].isdisjoint(lang_sets[v]):
                need_teach.add(u)
                need_teach.add(v)
        if not need_teach:
            return 0
        res = float('inf')
        for lang in range(1, n + 1):
            count = sum(lang not in lang_sets[user] for user in need_teach)
            res = min(res, count)
        return res
