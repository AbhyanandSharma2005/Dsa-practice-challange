class Solution:
    def minimumCost(self, source: str, target: str, original: List[char], changed: List[char], cost: List[int]) -> int:
        dist = [[float('inf')] * 26 for _ in range(26)]
        
        for i in range(26):
            dist[i][i] = 0
        
        for i in range(len(cost)):
            u = ord(original[i]) - ord('a')
            v = ord(changed[i]) - ord('a')
            dist[u][v] = min(dist[u][v], cost[i])
        
        for k in range(26):
            for i in range(26):
                for j in range(26):
                    if dist[i][k] != float('inf') and dist[k][j] != float('inf'):
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])
        
        totalCost = 0
        
        for i in range(len(source)):
            if source[i] != target[i]:
                u = ord(source[i]) - ord('a')
                v = ord(target[i]) - ord('a')
                
                if dist[u][v] == float('inf'):
                    return -1
                
                totalCost += dist[u][v]
        
        return totalCost