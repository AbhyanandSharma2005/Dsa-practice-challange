import sys
 
def main():
    data = sys.stdin.buffer.read().split()
    t = int(data[0])
    MOD = 1000000007
    L = 62
 
    # Precompute transition edges: edges[bn][is_last] = list of (from_state, to_state, mult)
    edges = {0: {0: [], 1: []}, 1: {0: [], 1: []}}
 
    for bn in (0, 1):
        for is_last in (0, 1):
            elist = []
            for s in range(8):
                tight = s >> 2
                reqbit = (s >> 1) & 1
                seenD = s & 1
                if reqbit == 0:
                    cb = 1
                    if tight:
                        if cb <= bn:
                            nt = 1 if cb == bn else 0
                            elist.append((s, nt*4+1*2+seenD, 1))
                    else:
                        elist.append((s, 0*4+1*2+seenD, 1))
                else:
                    cb = 0
                    if tight:
                        nt = 1 if cb == bn else 0
                        elist.append((s, nt*4+1*2+seenD, 1))
                    else:
                        elist.append((s, 0*4+1*2+seenD, 1))
                    if not is_last:
                        if seenD == 0:
                            cb = 1
                            if tight:
                                if cb <= bn:
                                    nt = 1 if cb == bn else 0
                                    elist.append((s, nt*4+0*2+1, 1))
                            else:
                                elist.append((s, 0*4+0*2+1, 1))
                        else:
                            if tight:
                                nt0 = 1 if 0 == bn else 0
                                elist.append((s, nt0*4+0*2+1, 1))
                                if 1 <= bn:
                                    nt1 = 1 if 1 == bn else 0
                                    elist.append((s, nt1*4+0*2+1, 1))
                            else:
                                elist.append((s, 0*4+0*2+1, 2))
            edges[bn][is_last] = elist
 
    out = []
    for k in range(1, t+1):
        n = int(data[k])
        st = [0]*8
        bn0 = (n >> (L-1)) & 1
        if 0 <= bn0:
            nt = 1 if 0 == bn0 else 0
            st[nt*4+1*2+0] += 1
        if 1 <= bn0:
            nt = 1 if 1 == bn0 else 0
            st[nt*4+1*2+0] += 1
            st[nt*4+0*2+1] += 1
 
        for idx in range(1, L):
            i = L-1-idx
            bn = (n >> i) & 1
            is_last = 1 if i == 0 else 0
            elist = edges[bn][is_last]
            new_st = [0]*8
            for (frm, to, mult) in elist:
                v = st[frm]
                if v:
                    new_st[to] = (new_st[to] + v*mult) % MOD
            st = new_st
 
        total = 0
        for s in range(8):
            if s & 1:
                total += st[s]
        out.append(str(total % MOD))
 
    sys.stdout.write('\n'.join(out) + '\n')
 
if __name__ == '__main__':
    main()