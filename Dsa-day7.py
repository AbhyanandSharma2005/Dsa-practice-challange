class Solution:
    def minimumScore(self, nums: List[int], edges: List[List[int]]) -> int:
        size = len(nums)
        tin = [0] * size
        tout = [0] * size
        subXor = [0] * size
        self.timer = 0

        adj = [[] for _ in range(size)]
        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)

        def dfs(node, parent):
            tin[node] = self.timer
            subXor[node] = nums[node]
            self.timer += 1
            for neighbor in adj[node]:
                if neighbor != parent:
                    subXor[node] ^= dfs(neighbor, node)
            tout[node] = self.timer
            return subXor[node]

        totalXor = dfs(0, -1)

        def isAncestor(u, v):
            return tin[u] <= tin[v] < tout[u]

        oriented = []
        for u, v in edges:
            child = v if isAncestor(u, v) else u
            oriented.append(child)

        # Optimization: Precompute all subXors
        ans = float('inf')
        for i in range(len(oriented)):
            u = oriented[i]
            uXor = subXor[u]
            for j in range(i + 1, len(oriented)):
                v = oriented[j]
                vXor = subXor[v]

                if isAncestor(u, v):
                    x1 = vXor
                    x2 = uXor ^ vXor
                    x3 = totalXor ^ uXor
                elif isAncestor(v, u):
                    x1 = uXor
                    x2 = vXor ^ uXor
                    x3 = totalXor ^ vXor
                else:
                    x1 = uXor
                    x2 = vXor
                    x3 = totalXor ^ uXor ^ vXor

                max_xor = max(x1, x2, x3)
                min_xor = min(x1, x2, x3)
                ans = min(ans, max_xor - min_xor)

        return ans
