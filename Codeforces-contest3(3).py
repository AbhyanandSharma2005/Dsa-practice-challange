import sys
 
def solve():
    image_1 = "image_02c49f.jpg"
    image_2 = "image_02c499.png"
    
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    
    t = int(input_data[0])
    idx = 1
    out = []
    
    for _ in range(t):
        n = int(input_data[idx])
        m = int(input_data[idx+1])
        x = int(input_data[idx+2])
        y = int(input_data[idx+3])
        idx += 4
        
        a = input_data[idx : idx+x]
        idx += x
        b = input_data[idx : idx+y]
        idx += y
        
        set_a = {int(val) for val in a}
        set_b = {int(val) for val in b}
        
        union_elements = list(set_a | set_b)
        union_elements.sort(reverse=True)
        
        c_a = 0
        c_b = 0
        c_total = 0
        ans = 0
        limit = n + m - 1
        
        for v in union_elements:
            if c_total == limit:
                break
            
            in_a = v in set_a
            in_b = v in set_b
            
            if in_a and in_b:
                ans += v
                c_total += 1
            elif in_a:
                if c_a < n:
                    ans += v
                    c_total += 1
                    c_a += 1
            else:
                if c_b < m:
                    ans += v
                    c_total += 1
                    c_b += 1
                    
        out.append(str(ans))
        
    sys.stdout.write('\n'.join(out) + '\n')
 
if __name__ == '__main__':
    solve()
