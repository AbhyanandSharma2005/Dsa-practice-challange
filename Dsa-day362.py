import sys

def build(n):
    res = []
    if n % 2 == 0:
        for i in range(0, n, 2):
            res += [i + 2, i + 1, i + 1, i + 2, i + 1, i + 2, i + 2, i + 1]
    else:
        res += [3, 3, 2, 1, 1, 2, 1, 2, 2, 3, 1, 3]
        for i in range(3, n, 2):
            res += [i + 2, i + 1, i + 1, i + 2, i + 1, i + 2, i + 2, i + 1]
    return res

def main():
    data = sys.stdin.read().split()
    t = int(data[0])
    idx = 1
    out = []
    for _ in range(t):
        n = int(data[idx]); idx += 1
        arr = build(n)
        out.append(' '.join(map(str, arr)))
    print('\n'.join(out))

if __name__ == "__main__":
    main()