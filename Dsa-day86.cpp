#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        if (power.empty()) {
            return 0;
        }

        map<int, long long> counts;
        for (int p : power) {
            counts[p] += p;
        }

        vector<int> unique_power;
        for (auto const& [p, total_damage] : counts) {
            unique_power.push_back(p);
        }

        int n = unique_power.size();
        if (n == 0) {
            return 0;
        }

        // dp[i] is the maximum total damage considering spells with damage up to unique_power[i]
        // using long long for dp to prevent overflow
        vector<long long> dp(n);

        // Base case: i = 0
        dp[0] = counts[unique_power[0]];

        for (int i = 1; i < n; ++i) {
            long long current_power = unique_power[i];
            long long current_damage = counts[current_power];

            // Choice 1: Skip all spells with damage current_power
            long long skip_damage = dp[i - 1];

            // Choice 2: Cast all spells with damage current_power
            long long cast_damage = current_damage;

            // Find the maximum damage from the set of non-conflicting previous spells
            // This search is efficient because it only happens once per DP state.
            int j = i - 1;
            while (j >= 0 && unique_power[j] >= current_power - 2) {
                j--;
            }

            if (j >= 0) {
                cast_damage += dp[j];
            }

            dp[i] = max(skip_damage, cast_damage);
        }

        return dp[n - 1];
    }
};