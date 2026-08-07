import sys
 
def main():
    data = sys.stdin.buffer.read().split()
    t = int(data[0])
    ns = [int(x) for x in data[1:1+t]]
    max_n = max(ns) if ns else 2
    limit = max_n + 2
    is_prime = bytearray([1]) * (limit + 1)
    is_prime[0:2] = b'\x00\x00'
    for i in range(2, int(limit**0.5) + 1):
        if is_prime[i]:
            is_prime[i*i:limit+1:i] = bytearray(len(range(i*i, limit+1, i)))
    out = []
    for n in ns:
        out.append("YES" if is_prime[n+1] else "NO")
    sys.stdout.write("\n".join(out) + "\n")
 
main()