import sys
import math
 
def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
        
    t = int(input_data[0])
    idx = 1
    out = []
    
    for _ in range(t):
        x = int(input_data[idx])
        y = int(input_data[idx+1])
        idx += 2
        
        S = x + y
        
        # O(1) math to find the maximum L such that L*(L+1)/2 <= x + y
        D = math.isqrt(1 + 8 * S)
        L = (D - 1) // 2
        T = L * (L + 1) // 2
        
        # Calculate boundaries
        low = max(0, T - y)
        high = min(x, T)
        
        # Find the ideal p
        mid_p = (x - y + T) // 2
        
        best_dist = float('inf')
        best_p = 0
        
        # Test the closest integers to the vertex of the parabola
        for cand_p in (mid_p - 1, mid_p, mid_p + 1):
            # Clamp candidate p to valid [low, high] bounds
            p = max(low, min(high, cand_p))
            q = T - p
            dist = (p - x)**2 + (q - y)**2
            
            if dist < best_dist:
                best_dist = dist
                best_p = p
                
        # O(L) String construction (using a list for faster string building in Python)
        rem = best_p
        res = ['Y'] * L
        
        for w in range(L, 0, -1):
            if rem >= w:
                res[L - w] = 'X'
                rem -= w
                
        out.append("".join(res))
        
    # Fast I/O print
    sys.stdout.write('\n'.join(out) + '\n')
 
if __name__ == '__main__':
    solve()