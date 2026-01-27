class Solution:
    def minCost(self, n: int, edges: List[List[int]]) -> int:
        from collections import defaultdict
        import heapq
        
        # Build adjacency lists for both outgoing and incoming edges
        outgoing = defaultdict(list)  # outgoing[u] = [(v, weight)]
        incoming = defaultdict(list)  # incoming[v] = [(u, weight)]
        
        for u, v, w in edges:
            outgoing[u].append((v, w))
            incoming[v].append((u, w))
        
        # Dijkstra's algorithm with state (cost, node, switch_used)
        # switch_used: 0 = not used, 1 = used
        pq = [(0, 0, 0)]  # (cost, node, switch_used)
        visited = set()
        
        while pq:
            cost, node, switch_used = heapq.heappop(pq)
            
            # Check if we reached the destination
            if node == n - 1:
                return cost
            
            # Skip if already visited this state
            state = (node, switch_used)
            if state in visited:
                continue
            visited.add(state)
            
            # Option 1: Traverse normal outgoing edges
            for neighbor, weight in outgoing[node]:
                new_state = (neighbor, 0)  # neighbor's switch not used yet
                if new_state not in visited:
                    heapq.heappush(pq, (cost + weight, neighbor, 0))
            
            # Option 2: If switch not used, reverse an incoming edge and traverse it
            if switch_used == 0:
                for prev_node, weight in incoming[node]:
                    # Reverse edge prev_node -> node to node -> prev_node
                    # Traverse at cost 2 * weight
                    new_state = (prev_node, 0)  # prev_node's switch status unchanged
                    if new_state not in visited:
                        heapq.heappush(pq, (cost + 2 * weight, prev_node, 0))
        
        return -1