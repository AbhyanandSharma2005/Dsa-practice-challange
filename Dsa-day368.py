import sys
def main():
    data = sys.stdin.buffer.read().split()
    idx = 0
    t = int(data[idx]); idx += 1
    out = []
    for _ in range(t):
        n = int(data[idx]); idx += 1
        a = list(map(int, data[idx:idx+n]))
        idx += n
        mn = min(a); mx = max(a)
        out.append(str((mx - mn + 1) // 2))
    sys.stdout.write('\n'.join(out))
main()