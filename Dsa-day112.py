from collections import defaultdict
from heapq import heappush, heappop

class Solution:
    def processQueries(self, c: int, connections: List[List[int]], queries: List[List[int]]) -> List[int]:
        online = [True] * (c + 1)
        adj = defaultdict(list)
        for u, v in connections:
            adj[u].append(v)
            adj[v].append(u)

        substations = []
        station_lookup = {}

        def dfs(node, idx):
            if node in station_lookup:
                return
            station_lookup[node] = idx
            heappush(substations[idx], node)
            for nei in adj[node]:
                dfs(nei, idx)

        for i in range(1, c + 1):
            if i not in station_lookup:
                substations.append([])
                dfs(i, len(substations) - 1)

        ans = []
        for t, x in queries:
            sid = station_lookup[x]
            heap = substations[sid]
            if t == 2:
                online[x] = False
                while heap and not online[heap[0]]:
                    heappop(heap)
            else:
                if online[x]:
                    ans.append(x)
                else:
                    while heap and not online[heap[0]]:
                        heappop(heap)
                    ans.append(heap[0] if heap else -1)
        return ans
