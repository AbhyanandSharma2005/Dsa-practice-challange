import sys

def main():
    data = sys.stdin.buffer.read().split()
    idx = 0
    t = int(data[idx]); idx += 1
    res = []
    for _ in range(t):
        n = int(data[idx]); idx += 1
        a = list(map(int, data[idx:idx+n])); idx += n
        total = 0
        cur_min = float('inf')
        for x in a:
            if x < cur_min:
                cur_min = x
            total += cur_min
        res.append(str(total))
    sys.stdout.write("\n".join(res) + "\n")

main()