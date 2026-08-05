import sys
 
def main():
    data = sys.stdin.buffer.read().split()
    idx = 0
    t = int(data[idx]); idx += 1
    out = []
    for _ in range(t):
        n = int(data[idx]); idx += 1
        a = data[idx].decode(); idx += 1
        b = data[idx].decode(); idx += 1
        if a.count('1') != b.count('1'):
            out.append("NO")
            continue
        oa = sum(1 for i in range(0, n, 2) if a[i] == '1')
        ob = sum(1 for i in range(0, n, 2) if b[i] == '1')
        out.append("YES" if oa == ob else "NO")
    sys.stdout.write('\n'.join(out) + '\n')
 
main()
