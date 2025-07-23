class Solution:
    def maximumGain(self, s: str, x: int, y: int) -> int:
        def remove_pattern(s: str, first: str, second: str, score: int) -> (str, int):
            stack = []
            total = 0
            for c in s:
                if stack and stack[-1] == first and c == second:
                    stack.pop()
                    total += score
                else:
                    stack.append(c)
            return ''.join(stack), total

        total_score = 0
        if x > y:
            s, score1 = remove_pattern(s, 'a', 'b', x)
            _, score2 = remove_pattern(s, 'b', 'a', y)
        else:
            s, score1 = remove_pattern(s, 'b', 'a', y)
            _, score2 = remove_pattern(s, 'a', 'b', x)
        
        return score1 + score2
