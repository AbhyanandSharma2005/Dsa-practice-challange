class Solution:
    def findMaxPathScore(self, edges: List[List[int]], online: List[bool], k: int) -> int:
        #given DAG atleast 2 nodes
        # given a list of paths (src, dest, cost)
        #given a list of online nodes
        #first and last nodes are always online
        # a valid path cost must not exceed 'k'
        # the score is the minimum cost along a path
        #return max score
        n = len(online)
        max_score = k
        min_score = 0 

        max_ans = -1
        while min_score <= max_score:
            mid = (min_score + max_score) // 2

            #prepare graph for kahns alg
            graph = [[] for _ in range(n)]
            indegree = [0] * n

            for u, v, w in edges:
                if w >= mid and online[u] and online[v]:  #for each w >= mid and online nodes for the edge
                    graph[u].append((v, w)) #append a dest - wt tuple
                    indegree[v] += 1
            
            #compute topo order
            from collections import deque

            q = deque()
            for i in range(n):
                if indegree[i] == 0:
                    q.append(i)

            topo = []

            while q:
                u = q.popleft()
                topo.append(u)

                for vertex, _ in graph[u]: #append subsequent vertices
                    indegree[vertex] -= 1
                    if indegree[vertex] == 0:
                        q.append(vertex)

            dist = [inf] * n
            dist[0] = 0

            for u in topo:
                if dist[u] == inf:
                    continue
                for v, w in graph[u]:
                    dist[v] = min(dist[v], dist[u] + w)

            if dist[n - 1] <= k:
                max_ans = max(max_ans, mid)
                min_score = mid + 1
            else:
                max_score = mid - 1
        
        return max_ans