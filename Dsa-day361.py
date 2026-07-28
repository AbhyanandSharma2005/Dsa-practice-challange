import sys

def main():
    input_data = sys.stdin.read().split()
    idx = 0
    t = int(input_data[idx]); idx += 1
    results = []
    for _ in range(t):
        n = int(input_data[idx]); idx += 1
        results.append(' '.join(map(str, range(n, 0, -1))))
    print('\n'.join(results))

main()