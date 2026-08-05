import sys
from collections import Counter
from functools import reduce
import operator
 
def solve(a, b):
    P = [0] + a
    Q = [0] + b
    Sp = reduce(operator.xor, a, 0)
    Sq = reduce(operator.xor, b, 0)
    pstar = Sp ^ Sq
    
    cp = Counter(P)
    if cp[pstar] == 0:
        return "NO"
        
    newset = [pstar ^ x for x in P]
    if Counter(newset) == Counter(Q):
        return "YES"
    return "NO"
 
def main():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
        
    t = int(input_data[0])
    idx = 1
    out = []
    
    for _ in range(t):
        n = int(input_data[idx])
        idx += 1
        
        a = [int(x) for x in input_data[idx:idx+n]]
        idx += n
        
        b = [int(x) for x in input_data[idx:idx+n]]
        idx += n
        
        out.append(solve(a, b))
        
    sys.stdout.write('\n'.join(out) + '\n')
 
if __name__ == '__main__':
    main()