class Solution:
    def minOperations(self, s: str) -> int:

        changes_start_0 = 0
        changes_start_1 = 0
        
        for i, ch in enumerate(s):
            if ch != str(i % 2):
                changes_start_0 += 1
            
            if ch != str((i + 1) % 2):
                changes_start_1 += 1
        
        return min(changes_start_0, changes_start_1)