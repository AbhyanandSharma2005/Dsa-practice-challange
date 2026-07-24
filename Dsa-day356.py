class Solution:
    def uniqueXorTriplets(self, nums: List[int]) -> int:
        max_val = max(nums)
        bits = 1
        while (1 << bits) <= max_val:
            bits += 1
        limit = 1 << bits

        unique_vals = sorted(set(nums))

        pair_xor = [False] * limit
        u_count = len(unique_vals)
        for i in range(u_count):
            for j in range(i, u_count):
                pair_xor[unique_vals[i] ^ unique_vals[j]] = True

        triple_xor = [False] * limit
        for p in range(limit):
            if pair_xor[p]:
                for v in unique_vals:
                    triple_xor[p ^ v] = True

        return sum(triple_xor)