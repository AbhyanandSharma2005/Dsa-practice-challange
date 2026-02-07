class Solution:
    def minimumDeletions(self, s: str) -> int:
        min_deletions = 0
        b_count = 0
        
        for char in s:
            if char == 'b':
                b_count += 1
            else:  # char == 'a'
                # Either delete this 'a' or delete all previous 'b's
                min_deletions = min(min_deletions + 1, b_count)
        
        return min_deletions