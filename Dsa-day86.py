from collections import Counter
from typing import List

class Solution:
    def maximumTotalDamage(self, power: List[int]) -> int:
        if not power:
            return 0

        # Calculate total damage for each unique power value
        counts = Counter(power)
        
        # Get sorted unique power values
        unique_power = sorted(counts.keys())
        n = len(unique_power)

        # Pre-calculate the total damage if all spells of a certain power are cast
        # total_damage_map[p] = p * count[p]
        total_damage_map = {p: p * counts[p] for p in unique_power}

        # dp[i] is the maximum total damage considering spells with damage up to unique_power[i]
        # Use a list for DP array
        dp = [0] * n

        # Base case: i = 0
        dp[0] = total_damage_map[unique_power[0]]

        # DP transition
        for i in range(1, n):
            current_p = unique_power[i]
            current_damage = total_damage_map[current_p]

            # Choice 1: Skip all spells with damage current_p
            skip_damage = dp[i - 1]

            # Choice 2: Cast all spells with damage current_p
            cast_damage = current_damage

            # Find the largest index j < i such that unique_power[j] < current_p - 2
            # This is the max damage from a non-conflicting subset
            j = i - 1
            while j >= 0 and unique_power[j] >= current_p - 2:
                j -= 1
            
            if j >= 0:
                cast_damage += dp[j]
            
            dp[i] = max(skip_damage, cast_damage)

        return dp[n - 1]