#include <vector>
#include <algorithm>

class Solution {
public:
    int numberOfPairs(std::vector<std::vector<int>>& points) {
        std::sort(points.begin(), points.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
            if (a[0] != b[0]) {
                return a[0] < b[0];
            }
            return a[1] > b[1];
        });
        
        int n = points.size();
        int count = 0;
        
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                
                if (points[i][1] >= points[j][1]) {
                    bool is_clear = true;
                    for (int k = i + 1; k < j; ++k) {
                        if (points[j][1] <= points[k][1] && points[k][1] <= points[i][1]) {
                            is_clear = false;
                            break;
                        }
                    }
                    if (is_clear) {
                        count++;
                    }
                }
            }
        }
        
        return count;
    }
};