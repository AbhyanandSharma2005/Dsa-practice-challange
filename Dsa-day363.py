import sys

def main():
    data = sys.stdin.buffer.read().split()
    idx = 0
    t = int(data[idx]); idx += 1
    res = []
    for _ in range(t):
        k = int(data[idx]); idx += 1
        c = data[idx:idx+k]; idx += k
        c = list(map(int, c))
        has_three = any(x >= 3 for x in c)
        count_two = sum(1 for x in c if x >= 2)
        if has_three or count_two >= 2:
            res.append("YES")
        else:
            res.append("NO")
    sys.stdout.write("\n".join(res) + "\n")

main()