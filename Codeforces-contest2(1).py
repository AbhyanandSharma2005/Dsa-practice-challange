import sys
from collections import Counter
 
def main():
    data = sys.stdin.read().split()
    idx = 0
    t = int(data[idx]); idx += 1
    res = []
    for _ in range(t):
        n = int(data[idx]); idx += 1
        a = [int(data[idx+i]) for i in range(n)]
        idx += n
        cnt = Counter(a)
        v, m = max(cnt.items(), key=lambda x: x[1])
        total = sum(a)
        wasted = max(0, 2*m - n - 2)
        res.append(total - wasted*v)
    print('\n'.join(map(str, res)))
 
main()