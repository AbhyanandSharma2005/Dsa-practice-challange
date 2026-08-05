import sys

def main():
    data = sys.stdin.read().split()
    idx = 0
    t = int(data[idx]); idx += 1
    res = []
    for _ in range(t):
        n, c = int(data[idx]), int(data[idx+1]); idx += 2
        a = list(map(int, data[idx:idx+n])); idx += n
        b = list(map(int, data[idx:idx+n])); idx += n

        sa = sum(a)
        sb = sum(b)
        diff = sa - sb

        no_reorder_ok = all(a[i] >= b[i] for i in range(n))
        a_sorted = sorted(a, reverse=True)
        b_sorted = sorted(b, reverse=True)
        reorder_ok = all(a_sorted[i] >= b_sorted[i] for i in range(n))

        best = None
        if no_reorder_ok:
            best = diff
        if reorder_ok:
            cand = c + diff
            if best is None or cand < best:
                best = cand

        res.append(str(best) if best is not None else "-1")

    print("\n".join(res))

main()