class Solution:
    def latestDayToCross(self, row: int, col: int, cells: List[List[int]]) -> int:
        def canCross(day):
            grid = [[0] * col for _ in range(row)]
            for i in range(day):
                r, c = cells[i]
                grid[r - 1][c - 1] = 1
            
            queue = []
            for c in range(col):
                if grid[0][c] == 0:
                    queue.append((0, c))
                    grid[0][c] = -1
            
            while queue:
                r, c = queue.pop(0)
                if r == row - 1:
                    return True
                for dr, dc in [(0, 1), (0, -1), (1, 0), (-1, 0)]:
                    nr, nc = r + dr, c + dc
                    if 0 <= nr < row and 0 <= nc < col and grid[nr][nc] == 0:
                        grid[nr][nc] = -1
                        queue.append((nr, nc))
            return False
        
        left, right = 0, len(cells)
        result = 0
        while left <= right:
            mid = (left + right) // 2
            if canCross(mid):
                result = mid
                left = mid + 1
            else:
                right = mid - 1
        return result