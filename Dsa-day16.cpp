#include <vector>
#include <unordered_map>
#include <numeric>
#include <algorithm>

class Solution {
public:
    long long minCost(std::vector<int>& basket1, std::vector<int>& basket2) {
        std::unordered_map<int, int> combined_freq;
        long long min_cost = 2e9 + 7;

        for (int x : basket1) {
            combined_freq[x]++;
            min_cost = std::min(min_cost, (long long)x);
        }
        for (int x : basket2) {
            combined_freq[x]++;
            min_cost = std::min(min_cost, (long long)x);
        }

        std::vector<int> misplaced;
        std::unordered_map<int, int> freq1;
        for (int x : basket1) {
            freq1[x]++;
        }

        for (auto const& [fruit, total_count] : combined_freq) {
            if (total_count % 2 != 0) {
                return -1;
            }
            int target_count = total_count / 2;
            int count1 = freq1.count(fruit) ? freq1[fruit] : 0;

            if (count1 > target_count) {
                for (int i = 0; i < count1 - target_count; ++i) {
                    misplaced.push_back(fruit);
                }
            } else if (count1 < target_count) {
                for (int i = 0; i < target_count - count1; ++i) {
                    misplaced.push_back(fruit);
                }
            }
        }
        
        std::sort(misplaced.begin(), misplaced.end());
        
        long long total_cost = 0;
        int k = misplaced.size() / 2;
        
        for (int i = 0; i < k; ++i) {
            total_cost += std::min((long long)misplaced[i], min_cost * 2);
        }
        
        return total_cost;
    }
};