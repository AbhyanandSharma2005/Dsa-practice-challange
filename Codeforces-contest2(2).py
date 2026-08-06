import sys
 
def solve(n, s):
    runs = []
    i = 0
    while i < n:
        j = i
        while j < n and s[j] == s[i]:
            j += 1
        runs.append((s[i], j - i))
        i = j
    
    R = len(runs)
    kept = [c for c, _ in runs]
    
    a = 0
    b = 0
    for c, length in runs:
        if c == '0':
            a += length - 1
        else:
            b += length - 1
            
    D = a - b
    l = 0
    r = R - 1
    peeled = 0
    
    while abs(D) > 1 and l <= r:
        desired = '1' if D > 1 else '0'
        
        if kept[l] == desired:
            val = kept[l]
            l += 1
        elif kept[r] == desired:
            val = kept[r]
            r -= 1
        else:
            val = kept[l]
            l += 1
            
        if val == '0':
            a += 1
        else:
            b += 1
            
        D = a - b
        peeled += 1
        
    if abs(D) > 1:
        return -1
        
    return (n - R) + peeled
 
def main():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
        
    t = int(input_data[0])
    idx = 1
    out = []
    
    for _ in range(t):
        n = int(input_data[idx])
        s = input_data[idx + 1]
        idx += 2
        out.append(str(solve(n, s)))
        
    sys.stdout.write('\n'.join(out) + '\n')
 
if __name__ == '__main__':
    main()