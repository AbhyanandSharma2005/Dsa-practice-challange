class Solution {
public:
    long long minTime(std::vector<int>& skill, std::vector<int>& mana) {
        int n = skill.size();
        int m = mana.size();

        // 1. Compute prefix sum of skills
        std::vector<long long> prefix(n);
        prefix[0] = skill[0];
        for (int i = 1; i < n; ++i) {
            prefix[i] = prefix[i-1] + skill[i];
        }

        // prev[i] will store finish_time(j-1, i)
        std::vector<long long> prev(n);

        // 2. Base case: Potion 0 (j=0)
        // finish_time(0, i) = start_time(0, 0) + prefix[i] * mana[0]
        // start_time(0, 0) = 0
        for (int i = 0; i < n; ++i) {
            prev[i] = prefix[i] * (long long)mana[0];
        }

        // 3. Process potions j = 1 to m-1
        for (int j = 1; j < m; ++j) {
            std::vector<long long> curr(n);
            long long mana_j = mana[j];
            long long s0 = 0; // Minimum start_time(j, 0)

            // s0_j = max_{0 <= i < n} { prev[i] - (prefix[i] - skill[i]) * mana[j] }
            for (int i = 0; i < n; ++i) {
                // S_{i-1} = prefix[i] - skill[i]
                long long s_i_minus_1 = prefix[i] - skill[i];
                s0 = std::max(s0, prev[i] - s_i_minus_1 * mana_j);
            }

            // finish_time(j, i) = s0 + prefix[i] * mana[j]
            for (int i = 0; i < n; ++i) {
                curr[i] = s0 + prefix[i] * mana_j;
            }
            prev = std::move(curr);
        }

        // The answer is finish_time(m-1, n-1)
        return prev[n-1];
    }
};