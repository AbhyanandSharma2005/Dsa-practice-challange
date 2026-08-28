from collections import Counter

class Solution:
    def lexGreaterPermutation(self, s: str, target: str) -> str:
        n = len(s)
        count = Counter(s)

        for i in range(n - 1, -2, -1):
            cur_count = count.copy()
            possible = True
            for j in range(i):
                if cur_count[target[j]] > 0:
                    cur_count[target[j]] -= 1
                else:
                    possible = False
                    break
            
            if not possible:
                continue

            next_char = None
            if i >= 0:
                for c in range(ord(target[i]) - ord('a') + 1, 26):
                    ch = chr(ord('a') + c)
                    if cur_count[ch] > 0:
                        next_char = ch
                        break
                if next_char is None:
                    continue

            res = []
            for j in range(i):
                res.append(target[j])
            
            if i >= 0:
                res.append(next_char)
                cur_count[next_char] -= 1

            for c in range(26):
                ch = chr(ord('a') + c)
                if cur_count[ch] > 0:
                    res.append(ch * cur_count[ch])

            ans = "".join(res)
            if i == -1:
                if ans > target:
                    return ans
            else:
                return ans

        return ""