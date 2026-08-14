import sys

def main():
    data = sys.stdin.buffer.read().split()
    idx = 0
    t = int(data[idx]); idx += 1
    out = []
    for _ in range(t):
        n = int(data[idx]); k = int(data[idx+1]); idx += 2
        s = data[idx]; idx += 1
        parity = [0] * k
        for pos in range(n):
            if s[pos] == 49:
                r = pos % k
                parity[r] ^= 1
        out.append("YES" if not any(parity) else "NO")
    sys.stdout.write("\n".join(out) + "\n")

if __name__ == "__main__":
    main()