import sys

def solve():
    MOD = 676767677
    data = sys.stdin.read().split()
    idx = 0
    t = int(data[idx]); idx += 1
    res = []
    for _ in range(t):
        n = int(data[idx]); idx += 1
        a = list(map(int, data[idx:idx+n])); idx += n
        total = sum(a)
        L = -1
        for i in range(n-1, -1, -1):
            if a[i] != 1:
                L = i
                break
        if L == -1:
            savings = max(n-1, 0)
        else:
            m1 = a[:L].count(1)
            m2 = a[L+1:].count(1)
            savings = m1 + max(m2-1, 0)
        ans = (total - savings) % MOD
        res.append(str(ans))
    print('\n'.join(res))

solve()