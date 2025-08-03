#include <vector>
#include <cmath>
#include <algorithm>

class Solution {
public:
    int maxTotalFruits(std::vector<std::vector<int>>& fruits, int startPos, int k) {
        int n = fruits.size();
        int max_fruits = 0;
        int left = 0;
        int current_fruits = 0;

        for (int right = 0; right < n; ++right) {
            current_fruits += fruits[right][1];

            while (true) {
                if (left > right) {
                    break;
                }
                
                int left_pos = fruits[left][0];
                int right_pos = fruits[right][0];
                
                long long dist_to_left = std::abs(static_cast<long long>(startPos) - left_pos);
                long long dist_to_right = std::abs(static_cast<long long>(startPos) - right_pos);
                
                long long steps_needed = std::min(dist_to_left, dist_to_right) + (right_pos - left_pos);
                
                if (steps_needed <= k) {
                    break;
                }
                
                current_fruits -= fruits[left][1];
                left++;
            }
            
            max_fruits = std::max(max_fruits, current_fruits);
        }
        
        return max_fruits;
    }
};