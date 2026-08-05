import sys
 
def solve():
    input_data = sys.stdin.read().split()
    idx = 0
    t = int(input_data[idx]); idx += 1
    results = []
    for _ in range(t):
        a = int(input_data[idx]); idx += 1
        b = int(input_data[idx]); idx += 1
        c = int(input_data[idx]); idx += 1
        rounds = 0
        while a != b and b != c and a != c:
            tokens = [a, b, c]
            max_i = tokens.index(max(tokens))
            min_i = tokens.index(min(tokens))
            tokens[max_i] -= 1
            tokens[min_i] += 1
            a, b, c = tokens
            rounds += 1
        results.append(rounds)
    print('\n'.join(map(str, results)))
 
solve()