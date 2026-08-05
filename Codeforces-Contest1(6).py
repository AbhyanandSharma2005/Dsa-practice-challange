import sys
from bisect import bisect_left
 
def main():
    data = sys.stdin.buffer.read().split()
    if not data:
        return
        
    idx = 0
    t = int(data[idx])
    idx += 1
    
    out = []
    for _ in range(t):
        n = int(data[idx])
        idx += 1
        
        b = []
        has_pos = False
        s = 0
        
        for _ in range(n):
            x = int(data[idx])
            b.append(x)
            s += x
            if x > 0:
                has_pos = True
            idx += 1
            
        if not has_pos or s < 1:
            out.append("-1")
            continue
            
        vals = sorted(set(b))
        m = len(vals)
        
        cnt = [0] * m
        vidx = {v: i for i, v in enumerate(vals)}
        for x in b:
            cnt[vidx[x]] += 1
            
        nxt = list(range(m + 1))
        
        C = 0
        res = []
        
        for _ in range(n):
            L = 1 - C
            
            startIdx = bisect_left(vals, L)
            
            x = startIdx
            while x < m and nxt[x] != x:
                nxt[x] = nxt[nxt[x]]
                x = nxt[x]
                
            v = vals[x]
            C += v
            res.append(str(C))
            
            cnt[x] -= 1
            if cnt[x] == 0:
                nxt[x] = x + 1
                
        out.append(' '.join(res))
        
    sys.stdout.write('\n'.join(out) + '\n')
 
if __name__ == "__main__":
    main()