import sys

def main():
    data = sys.stdin.buffer.read().split()
    idx = 0
    t = int(data[idx]); idx += 1
    res = []
    for _ in range(t):
        n = int(data[idx]); idx += 1
        a = data[idx].decode(); idx += 1
        b = data[idx].decode(); idx += 1
        c1 = 0
        c2 = 0
        for i in range(n):
            ca = a[i]
            cb = b[i]
            if ca == '(' and cb == '(':
                c1 += 1
            elif ca == ')' and cb == ')':
                c2 += 1
        if c1 != c2:
            res.append("NO")
            continue
        bal_a = 0
        bal_b = 0
        ok = True
        for i in range(n):
            ca = a[i]
            cb = b[i]
            if ca == '(' and cb == '(':
                bal_a += 1
                bal_b += 1
            elif ca == ')' and cb == ')':
                bal_a -= 1
                bal_b -= 1
                if bal_a < 0 or bal_b < 0:
                    ok = False
                    break
            else:
                if bal_a <= bal_b:
                    bal_a += 1
                    bal_b -= 1
                else:
                    bal_b += 1
                    bal_a -= 1
                if bal_a < 0 or bal_b < 0:
                    ok = False
                    break
        if ok and bal_a == 0 and bal_b == 0:
            res.append("YES")
        else:
            res.append("NO")
    sys.stdout.write("\n".join(res) + "\n")

main()