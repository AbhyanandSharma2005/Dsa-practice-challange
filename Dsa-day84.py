class Solution:
    def minTime(self, skill: list[int], mana: list[int]) -> int:
        n = len(skill)
        m = len(mana)

        # 1. Compute prefix sum of skills
        # prefix[i] = skill[0] + ... + skill[i]
        prefix = [0] * n
        prefix[0] = skill[0]
        for i in range(1, n):
            prefix[i] = prefix[i-1] + skill[i]

        # prev[i] will store finish_time(j-1, i)
        prev = [0] * n

        # 2. Base case: Potion 0 (j=0)
        # finish_time(0, i) = prefix[i] * mana[0]
        mana_0 = mana[0]
        for i in range(n):
            prev[i] = prefix[i] * mana_0

        # 3. Process potions j = 1 to m-1
        for j in range(1, m):
            curr = [0] * n
            mana_j = mana[j]
            s0 = 0 # Minimum start_time(j, 0)

            # s0_j = max_{0 <= i < n} { prev[i] - (prefix[i] - skill[i]) * mana[j] }
            for i in range(n):
                # S_{i-1} = prefix[i] - skill[i]
                s_i_minus_1 = prefix[i] - skill[i]
                s0 = max(s0, prev[i] - s_i_minus_1 * mana_j)

            # finish_time(j, i) = s0 + prefix[i] * mana[j]
            for i in range(n):
                curr[i] = s0 + prefix[i] * mana_j
            prev = curr

        # The answer is finish_time(m-1, n-1)
        return prev[n-1]