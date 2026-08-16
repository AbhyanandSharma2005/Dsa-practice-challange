#include <vector>
#include <cmath>

class Solution {
public:
    bool stoneGameIX(std::vector<int>& stones) {
        int counts[3] = {0, 0, 0};
        
        for (int stone : stones) {
