import sys
input = sys.stdin.readline

MOD = 676767677

def main():
    t = int(input())
    out = []
    for _ in range(t):
        x, y = map(int, input().split())
        s = x - y
        a = [1] * x + [-1] * y

        if s == 0:
            ans = 1
        else:
            d = abs(s)
            ans = 0
            i = 1
            while i * i <= d:
                if d % i == 0:
                    ans += 1
                    if i != d // i:
                        ans += 1
                i += 1
            ans %= MOD

        out.append(str(ans))
        out.append(' '.join(map(str, a)))

    print('\n'.join(out))

main()