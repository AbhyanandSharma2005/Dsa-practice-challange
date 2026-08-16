#include <vector>
#include <cmath>

class Solution {
public:
    bool stoneGameIX(std::vector<int>& stones) {
        int c0 = 0, c1 = 0, c2 = 0;
        
        for (int x : stones) {
            (x % 3 == 0) ? c0++ : (x % 3 == 1) ? c1++ : c2++;
        }
        
        return (c0 & 1) ? std::abs(c1 - c2) > 2 : (c1 && c2);
    }
};