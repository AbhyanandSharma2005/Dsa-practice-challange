from heapq import heappush, heappop
class Solution:
    def minimumCost(self, source: str, target: str, original: List[str], changed: List[str], cost: List[int]) -> int:
        MOD = 10 ** 9 + 7
        BASE = 131
        
        # 1. Setup Rolling Hash Powers
        max_len = len(source)
        powers = [1] * (max_len + 1)
        for i in range(1, max_len + 1):
            powers[i] = (powers[i - 1] * BASE) % MOD

        # Helper to compute hash of a single string
        def get_hash(s):
            h = 0
            for char in s:
                h = (h * BASE + ord(char)) % MOD
            return h

        # 2. Map all unique substrings to IDs
        all_hashes = set()
        for i in range(len(original)):
            all_hashes.add(get_hash(original[i]))
            all_hashes.add(get_hash(changed[i]))
            
        hash_to_id = {h: i for i, h in enumerate(all_hashes)}
        m = len(all_hashes)
        
        # 3. Build Graph
        graph = [[] for _ in range(m)]
        for i in range(len(original)):
            u = hash_to_id[get_hash(original[i])]
            v = hash_to_id[get_hash(changed[i])]
            graph[u].append((cost[i], v))

        # 4. Precompute All-Pairs Shortest Paths (Dijkstra from each node)
        min_costs = {} 

        def dijkstra(src_id):
            dist = [float("inf")] * m
            dist[src_id] = 0
            heap = [(0, src_id)]
            
            while heap:
                d, u = heappop(heap)
                if d > dist[u]:
                    continue
                for w, v in graph[u]:
                    if dist[u] + w < dist[v]:
                        dist[v] = dist[u] + w
                        heappush(heap, (dist[v], v))
            return dist

        # Run Dijkstra for every unique substring present in rules
        for h in all_hashes:
            u_id = hash_to_id[h]
            min_costs[u_id] = dijkstra(u_id)

        # 5. Prepare Source/Target Hashing for O(1) substring lookups
        def get_prefix_hashes(s):
            n = len(s)
            pre = [0] * (n + 1)
            for i in range(n):
                pre[i + 1] = (pre[i] * BASE + ord(s[i])) % MOD
            return pre

        pre_source = get_prefix_hashes(source)
        pre_target = get_prefix_hashes(target)
        n = len(source)
        
        # 6. Dynamic Programming
        # dp[i] = min cost to solve suffix source[i:] -> target[i:]
        dp = [float("inf")] * (n + 1)
        dp[n] = 0
        
        # Optimization: only check lengths that actually exist in 'original'
        valid_lengths = set(len(s) for s in original)

        for i in range(n - 1, -1, -1):
            # Option 1: Characters match, zero cost
            if source[i] == target[i]:
                dp[i] = min(dp[i], dp[i + 1])
            
            # Option 2: Replace substring of length 'length'
            for length in valid_lengths:
                if i + length <= n:
                    l, r = i, i + length - 1
                    
                    # Compute rolling hash for source and target substring
                    h_src = (pre_source[r + 1] - pre_source[l] * powers[length]) % MOD
                    h_tgt = (pre_target[r + 1] - pre_target[l] * powers[length]) % MOD
                    
                    if h_src in hash_to_id and h_tgt in hash_to_id:
                        u = hash_to_id[h_src]
                        v = hash_to_id[h_tgt]
                        
                        # If a valid path exists between these substrings
                        cost_path = min_costs[u][v]
                        if cost_path != float("inf") and dp[i + length] != float("inf"):
                            dp[i] = min(dp[i], cost_path + dp[i + length])

        return dp[0] if dp[0] != float("inf") else -1