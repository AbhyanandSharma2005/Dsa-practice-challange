class Solution:
    def canPartitionGrid(self, grid: List[List[int]]) -> bool:
        m, n = len(grid), len(grid[0])
        total_sum = sum(sum(row) for row in grid)
        
        row_sums = [sum(row) for row in grid]
        col_sums = [0] * n
        for j in range(n):
            for i in range(m):
                col_sums[j] += grid[i][j]

        val_map = defaultdict(list)
        for r in range(m):
            for c in range(n):
                val_map[grid[r][c]].append((r, c))

        def is_valid_removal(target_val, r_range, c_range):
            if target_val not in val_map:
                return False
            
            r_start, r_end = r_range
            c_start, c_end = c_range
            h, w = r_end - r_start + 1, c_end - c_start + 1
            
            for r, c in val_map[target_val]:
                if r_start <= r <= r_end and c_start <= c <= c_end:
                    if h > 1 and w > 1:
                        return True
                    if h == 1:
                        if c == c_start or c == c_end: return True
                    elif w == 1:
                        if r == r_start or r == r_end: return True
            return False

        curr_top_sum = 0
        for i in range(m - 1):
            curr_top_sum += row_sums[i]
            curr_bot_sum = total_sum - curr_top_sum
            diff = abs(curr_top_sum - curr_bot_sum)
            
            if diff == 0: return True
            
            if curr_top_sum > curr_bot_sum:
                if is_valid_removal(diff, (0, i), (0, n - 1)): return True
            else:
                if is_valid_removal(diff, (i + 1, m - 1), (0, n - 1)): return True

        curr_left_sum = 0
        for j in range(n - 1):
            curr_left_sum += col_sums[j]
            curr_right_sum = total_sum - curr_left_sum
            diff = abs(curr_left_sum - curr_right_sum)
            
            if diff == 0: return True
            
            if curr_left_sum > curr_right_sum:
                if is_valid_removal(diff, (0, m - 1), (0, j)): return True
            else:
                if is_valid_removal(diff, (0, m - 1), (j + 1, n - 1)): return True

        return False