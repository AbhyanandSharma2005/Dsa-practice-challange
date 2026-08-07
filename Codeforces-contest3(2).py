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
        a = [int(x) for x in a]
        vals = []
        cnts = []
        for x in a:
            if vals and vals[-1] == x:
                cnts[-1] += 1
            else:
                vals.append(x)
                cnts.append(1)
        L = len(vals)
        ans = L
        for i in range(L - 1):
            X = vals[i]; cx = cnts[i]
            Y = vals[i+1]; cy = cnts[i+1]
            if cx >= 2:
                leftLen = i + 1
            else:
                adj = 1 if (i - 1 >= 0 and vals[i-1] == Y) else 0
                leftLen = i - adj
            if cy >= 2:
                rightLen = L - 1 - i
            else:
                adj = 1 if (i + 2 <= L - 1 and vals[i+2] == X) else 0
                rightLen = (L - i - 2) - adj
            total = leftLen + 2 + rightLen
            if total > ans:
                ans = total
        out.append(str(ans))
    sys.stdout.write("\n".join(out) + "\n")
 
main()