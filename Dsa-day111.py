class Solution:
    def findXSum(self, nums: List[int], k: int, x: int) -> List[int]:
        def key(f, v):
            return (-f, -v)

        freq = Counter()
        top, rest = [], []
        top_sum = 0
        final = []

        def thallu(lst, fv):
            bisect.insort(lst, key(fv[0], fv[1]))

        def thuku(lst, fv):
            kv = key(fv[0], fv[1])
            idx = bisect.bisect_left(lst, kv)
            if idx < len(lst) and lst[idx] == kv:
                lst.pop(idx)
                return True
            return False

        def order():
            nonlocal top_sum
            while len(top) > x:
                worst = top.pop()
                f, v = -worst[0], -worst[1]
                top_sum -= f * v
                bisect.insort(rest, worst)
            while len(top) < x and rest:
                best = rest.pop(0)
                f, v = -best[0], -best[1]
                top_sum += f * v
                bisect.insort(top, best)
            while rest and top and rest[0] < top[-1]:
                best = rest.pop(0)
                worst = top.pop()
                f1, v1 = -best[0], -best[1]
                f2, v2 = -worst[0], -worst[1]
                top_sum += f1 * v1 - f2 * v2
                bisect.insort(top, best)
                bisect.insort(rest, worst)

        for i, v in enumerate(nums):
            old_f = freq[v]
            if old_f > 0:
                if thuku(top, (old_f, v)):
                    top_sum -= old_f * v
                else:
                    thuku(rest, (old_f, v))
            freq[v] = old_f + 1
            thallu(rest, (freq[v], v))
            order()

            if i >= k:
                left = nums[i - k]
                old_f = freq[left]
                if thuku(top, (old_f, left)):
                    top_sum -= old_f * left
                else:
                    thuku(rest, (old_f, left))
                new_f = old_f - 1
                if new_f > 0:
                    freq[left] = new_f
                    thallu(rest, (new_f, left))
                else:
                    del freq[left]
                order()

            if i >= k - 1:
                final.append(top_sum)

        return final