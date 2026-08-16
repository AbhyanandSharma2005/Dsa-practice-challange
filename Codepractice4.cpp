// #include <vector>
// #include <cmath>

// class Solution {
// public:
//     bool stoneGameIX(std::vector<int>& stones) {
//         int counts[3] = {0, 0, 0};
        
//         for (int stone : stones) {
//             counts[stone % 3]++;
//         }
        
//         if (counts[0] % 2 == 0) {
//             return counts[1] > 0 && counts[2] > 0;
//         } else {
//             return std::abs(counts[1] - counts[2]) > 2;
//         }
//     }
// };

// #include <vector>
// #include <algorithm>

// class Solution {
// private:
//     bool canAliceWin(int c0, int c1, int c2) {
//         if (c1 == 0) return false; 
        
//         int k = std::min(c1 - 1, c2); 
//         int played_non_zero = 1 + 2 * k; 
        
//         if (c1 - 1 > k) {
//             played_non_zero++;
//         }
        
//         int total_played = played_non_zero + c0; 
        
//         if (total_played == c0 + c1 + c2) {
//             return false; 
//         }
        
//         return total_played % 2 != 0; 
//     }
    
// public:
//     bool stoneGameIX(std::vector<int>& stones) {
//         int counts[3] = {0, 0, 0};
//         for (int stone : stones) {
//             counts[stone % 3]++;
//         }
        
//         return canAliceWin(counts[0], counts[1], counts[2]) || 
//                canAliceWin(counts[0], counts[2], counts[1]);
//     }
// };