#include <vector>
#include <algorithm>
#include <cmath>

class Solution {
public:
    std::vector<int> successfulPairs(std::vector<int>& spells, std::vector<int>& potions, long long success) {
        std::sort(potions.begin(), potions.end());
        
        int n = spells.size();
        int m = potions.size();
        std::vector<int> pairs(n);

        for (int i = 0; i < n; ++i) {
            long long spell_strength = spells[i];
            
            long long required_potion_strength = (success + spell_strength - 1) / spell_strength;
            
            auto it = std::lower_bound(potions.begin(), potions.end(), required_potion_strength);
            
            int k = std::distance(potions.begin(), it);
            
            pairs[i] = m - k;
        }
        
        return pairs;
    }
};