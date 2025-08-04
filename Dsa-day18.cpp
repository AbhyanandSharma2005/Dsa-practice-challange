#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    int totalFruit(std::vector<int>& fruits) {
        int n = fruits.size();
        if (n <= 2) {
            return n;
        }

        std::unordered_map<int, int> fruitCounts;
        int maxFruits = 0;
        int left = 0;

        for (int right = 0; right < n; right++) {
            fruitCounts[fruits[right]]++;

            while (fruitCounts.size() > 2) {
                int leftFruit = fruits[left];
                fruitCounts[leftFruit]--;
                if (fruitCounts[leftFruit] == 0) {
                    fruitCounts.erase(leftFruit);
                }
                left++;
            }
            
            maxFruits = std::max(maxFruits, right - left + 1);
        }
        
        return maxFruits;
    }
};