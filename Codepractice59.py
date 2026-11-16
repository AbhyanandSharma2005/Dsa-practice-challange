class Solution:
    def digitSum(self, s: str, k: int) -> str:
        # Repeat rounds while the string length exceeds k
        while len(s) > k:
            next_s = []
            
            # Process the string in consecutive chunks of size k
            for i in range(0, len(s), k):
                chunk = s[i : i + k]
                chunk_sum = sum(int(digit) for digit in chunk)
                next_s.append(str(chunk_sum))
            
            # Merge the group sums into the new string
            s = "".join(next_s)
            
        return s
