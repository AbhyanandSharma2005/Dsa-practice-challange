import sys
 
def solve():
    data = sys.stdin.read().split()
    idx = 0
    t = int(data[idx]); idx += 1
    out = []
    for _ in range(t):
        n = int(data[idx]); idx += 1
        s = data[idx]; idx += 1
        blocks = []
        i = 0
        while i < n:
            j = i
            while j < n and s[j] == s[i]:
                j += 1
            blocks.append((s[i], i, j - i))
            i = j
        B = len(blocks)
        best_delta = None
        for k in range(B):
            ch, start, length = blocks[k]
            end = start + length - 1
            lo = max(start, 1)
            hi = min(end, n - 2)
            if lo <= hi:
                if length > 1:
                    delta = 0
                else:
                    if k > 0 and k < B - 1:
                        left_char = blocks[k - 1][0]
                        right_char = blocks[k + 1][0]
                        delta = -2 if left_char == right_char else -1
                    else:
                        continue
                if best_delta is None or delta < best_delta:
                    best_delta = delta
        out.append(str(B + best_delta))
    sys.stdout.write('\n'.join(out) + '\n')
 
solve()