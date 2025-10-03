class Solution:
    def trapRainWater(self, heightMap: list[list[int]]) -> int:
        if not heightMap or not heightMap[0]:
            return 0
        
        m, n = len(heightMap), len(heightMap[0])
        visited = [[False] * n for _ in range(m)]
        min_heap = []
        
        for i in range(m):
            heapq.heappush(min_heap, (heightMap[i][0], i, 0))
            heapq.heappush(min_heap, (heightMap[i][n-1], i, n-1))
            visited[i][0] = visited[i][n-1] = True
        for j in range(1, n - 1):
            heapq.heappush(min_heap, (heightMap[0][j], 0, j))
            heapq.heappush(min_heap, (heightMap[m-1][j], m-1, j))
            visited[0][j] = visited[m-1][j] = True
        
        directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]
        result = 0
        max_height = 0
        
        while min_heap:
            height, x, y = heapq.heappop(min_heap)
            max_height = max(max_height, height)
            
            for dx, dy in directions:
                nx, ny = x + dx, y + dy
                if 0 <= nx < m and 0 <= ny < n and not visited[nx][ny]:
                    visited[nx][ny] = True
                    if heightMap[nx][ny] < max_height:
                        result += max_height - heightMap[nx][ny]
                    heapq.heappush(min_heap, (max(heightMap[nx][ny], max_height), nx, ny))
        
        return result