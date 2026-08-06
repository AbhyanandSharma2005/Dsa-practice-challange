import sys
 
def solve():
    data = sys.stdin.buffer.read().split()
    idx = 0
    t = int(data[idx]); idx += 1
    res = []
    for _ in range(t):
        n = int(data[idx]); idx += 1
        a = list(map(int, data[idx:idx+n])); idx += n
        if n == 1:
            res.append(str(a[0]))
            continue
        b = [a[k] - a[k-1] for k in range(1, n)]
        m = len(b)
        i = 0
        while i < m:
            j = i
            p = b[i] % 2
            while j + 1 < m and b[j+1] % 2 == p:
                j += 1
            b[i:j+1] = sorted(b[i:j+1])
            i = j + 1
        for k in range(1, n):
            a[k] = a[k-1] + b[k-1]
        res.append(' '.join(map(str, a)))
    sys.stdout.write('\n'.join(res) + '\n')
 
solve()