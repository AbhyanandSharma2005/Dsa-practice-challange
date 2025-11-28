class Solution:
    def maxKDivisibleComponents(self, n: int, edges: List[List[int]], values: List[int], k: int) -> int:
        adj = [[] for _ in range(n)]
        for a, b in edges:
            adj[a].append(b)
            adj[b].append(a)
        
        self.ans = 0
        
        def dfs(node, parent):
            total = values[node]
            for child in adj[node]:
                if child != parent:
                    sub = dfs(child, node)
                    total += sub
            if total % k == 0:
                self.ans += 1
                return 0
            return total
        
        dfs(0, -1)
        return self.ans