class Solution:
    def mapWordWeights(self, words: List[str], weights: List[int]) -> str:
        ans = []

        for word in words:
            total = sum(weights[ord(ch) - ord('a')] for ch in word)

            mod = total % 26

            ans.append(chr(ord('z') - mod))

        return ''.join(ans)