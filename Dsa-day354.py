import sys

def main():
    data = sys.stdin.buffer.read().split()
    idx = 0
    t = int(data[idx]); idx += 1
    out = []
    for _ in range(t):
        n = int(data[idx]); idx += 1
        a = data[idx:idx+n]
        idx += n
        prefix = 0
        best = None
        res = []
        for j in range(1, n+1):
            prefix += int(a[j-1])
            val = prefix // j
            if best is None or val < best:
                best = val
            res.append(best)
        out.append(' '.join(map(str, res)))
    sys.stdout.write('\n'.join(out) + '\n')

main()