from bisect import bisect_left

class Solution:
    def successfulPairs(self, spells: List[int], potions: List[int], success: int) -> List[int]:
        potions.sort()
        n = len(spells)
        m = len(potions)
        pairs = [0] * n

        for i in range(n):
            spell_strength = spells[i]
            
            required_potion_strength = (success + spell_strength - 1) // spell_strength
            
            k = bisect_left(potions, required_potion_strength)
            
            pairs[i] = m - k
            
        return pairs