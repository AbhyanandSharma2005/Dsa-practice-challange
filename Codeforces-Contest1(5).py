import sys
from collections import Counter
 
def main():
    data = sys.stdin.buffer.read().split()
    idx = 0
    t = int(data[idx]); idx += 1
    out = []
    for _ in range(t):
        n = int(data[idx]); idx += 1
        b = data[idx:idx+n]
        idx += n
        b = [int(x) for x in b]
        cnt = Counter(b)
        vals = sorted(cnt.keys())
        if vals[0] != 0:
            out.append("-1")
            continue
        k = len(vals)
        vmap = {}
        valid = True
        prev_v = 0
        for j in range(k - 1):
            Bj = vals[j]
            Bj1 = vals[j + 1]
            cj = cnt[Bj]
            diff = Bj1 - Bj
            if diff % cj != 0:
                valid = False
                break
            vj = diff // cj
            if vj <= prev_v:
                valid = False
                break
            vmap[Bj] = vj
            prev_v = vj
        if not valid:
            out.append("-1")
            continue
        last_B = vals[-1]
        vlast = 1 if k == 1 else prev_v + 1
        vmap[last_B] = vlast
        a = [vmap[x] for x in b]
        out.append(' '.join(map(str, a)))
    sys.stdout.write('\n'.join(out) + '\n')
 
if __name__ == "__main__":
    main()