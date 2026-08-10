import sys

def solve(n):
    total = 0
    b = 1
    while b <= n:
        q = n // b
        b2 = n // q
        cnt = b2 - b + 1
        total += q * q * cnt
        b = b2 + 1
    return total

def main():
    data = sys.stdin.read().split()
    t = int(data[0])
    idx = 1
    out = []
    for _ in range(t):
        n = int(data[idx]); idx += 1
        out.append(str(solve(n)))
    print('\n'.join(out))

main()