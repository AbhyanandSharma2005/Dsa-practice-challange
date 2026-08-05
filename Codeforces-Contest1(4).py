import sys
 
def main():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    
    t = int(input_data[0])
    idx = 1
    out = []
    
    for _ in range(t):
        n = int(input_data[idx])
        a = input_data[idx+1]
        b = input_data[idx+2]
        idx += 3
        
        a_even = []
        a_odd = []
        b_even = []
        b_odd = []
        
        for i in range(n):
            if a[i] == '1':
                if i % 2 == 0:
                    a_even.append(i)
                else:
                    a_odd.append(i)
            if b[i] == '1':
                if i % 2 == 0:
                    b_even.append(i)
                else:
                    b_odd.append(i)
                    
        if len(a_even) != len(b_even) or len(a_odd) != len(b_odd):
            out.append("-1")
        else:
            ans = 0
            for i in range(len(a_even)):
                ans += abs(a_even[i] - b_even[i]) // 2
            for i in range(len(a_odd)):
                ans += abs(a_odd[i] - b_odd[i]) // 2
            out.append(str(ans))
            
    sys.stdout.write('\n'.join(out) + '\n')
 
if __name__ == '__main__':
    main()