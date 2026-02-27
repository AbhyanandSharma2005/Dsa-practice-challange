class Solution:
    def minOperations(self, s: str, k: int) -> int:

        
        o = s.count("1")
        z = s.count("0")

        odd = SortedList(range(1, len(s) + 1, 2))
        even = SortedList(range(0, len(s) + 1, 2))

        queue = deque([(o, 0)])
        # seen = set()

        even.remove(o) if o % 2 == 0 else odd.remove(o) 

        while queue:
            # print(queue)
            o, a = queue.popleft()

            if len(s) - o == 0:
                return a

            mx = min(len(s) - o, k)
            mn = max(0, k - o)

            # print(mx, mn)

            # if (o) in seen: continue
            # seen.add(o)

            # for i in range(mn, mx + 1):
            #     tmp = len(s) - (((len(s) - o) - i) + (k - i))
            #     if tmp % 2 == 0 and tmp in even:
            #         queue.append((tmp, a + 1))
            #         even.remove(tmp)
            #     elif tmp in odd:
            #         queue.append((tmp, a + 1))
            #         odd.remove(tmp)

            first = len(s) - (((len(s) - o) - mn) + (k - mn))
            last = len(s) - (((len(s) - o) - mx) + (k - mx))

            node = even if first % 2 == 0 else odd
            idx = node.bisect_left(first)
            while idx < len(node) and node[idx] <= last:
                queue.append((node[idx], a + 1))
                node.pop(idx)

                
        return -1