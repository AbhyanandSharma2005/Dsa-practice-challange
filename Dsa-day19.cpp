#include <vector>

class Solution {
public:
    int numOfUnplacedFruits(std::vector<int>& fruits, std::vector<int>& baskets) {
        int n = fruits.size();
        std::vector<bool> usedBaskets(n, false);
        int unplacedFruitsCount = 0;
        
        for (int i = 0; i < n; i++) {
            int fruitSize = fruits[i];
            bool placed = false;
            for (int j = 0; j < n; j++) {
                if (!usedBaskets[j] && baskets[j] >= fruitSize) {
                    usedBaskets[j] = true;
                    placed = true;
                    break;
                }
            }
            
            if (!placed) {
                unplacedFruitsCount++;
            }
        }
        
        return unplacedFruitsCount;
    }
};