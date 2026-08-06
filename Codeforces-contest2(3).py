import sys
 
def main():
    data = sys.stdin.buffer.read().split()
    pos = 0
    t = int(data[pos]); pos += 1
    res = []
    LOG = 20
    for _ in range(t):
        n = int(data[pos]); m = int(data[pos+1]); pos += 2
        v = list(map(int, data[pos:pos+n])); pos += n
        a_flat = list(map(int, data[pos:pos+n*m])); pos += n*m
 
        allvals = sorted(set(a_flat))
        V = len(allvals)
        val_to_idx = {}
        for i, val in enumerate(allvals):
            val_to_idx[val] = i + 1
 
        cnt_arr = [0]*(V+1)
        bit_cnt = [0]*(V+1)
        bit_sum = [0]*(V+1)
 
        total_count = 0
        total_sum = 0
        best = m
 
        for k in range(n, 0, -1):
            start = (k-1)*m
            row = a_flat[start:start+m]
            for x in row:
                ci = val_to_idx[x]
                i = ci
                while i <= V:
                    bit_cnt[i] += 1
                    bit_sum[i] += x
                    i += i & (-i)
                cnt_arr[ci] += 1
                total_count += 1
                total_sum += x
 
            target = v[k-1]
            if target <= total_sum:
                T = total_sum - target
                p = 0
                cur_sum = 0
                cur_cnt = 0
                bitmask = 1 << LOG
                while bitmask > 0:
                    nxt = p + bitmask
                    if nxt <= V:
                        s = cur_sum + bit_sum[nxt]
                        if s <= T:
                            p = nxt
                            cur_sum = s
                            cur_cnt += bit_cnt[nxt]
                    bitmask >>= 1
                rem = T - cur_sum
                y = cur_cnt
                if p < V:
                    val = allvals[p]
                    avail = cnt_arr[p+1]
                    extra = rem // val
                    if extra > avail:
                        extra = avail
                    y += extra
                c = total_count - y
                if c < best:
                    best = c
 
        res.append(str(best))
 
    sys.stdout.write('\n'.join(res) + '\n')
 
main()
