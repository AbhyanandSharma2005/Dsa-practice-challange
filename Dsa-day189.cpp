#include <vector>
#include <climits>

class Solution {
public:
    int minimumPairRemoval(std::vector<int>& nums) {
        auto is_non_decreasing = [](const std::vector<int>& arr, int length) -> bool {
            for (int i = 1; i < length; ++i) {
                if (arr[i] < arr[i - 1]) return false;
            }
            return true;
        };

        int ans = 0;
        int n = nums.size();
        std::vector<int> arr = nums;

        while (!is_non_decreasing(arr, n)) {
            ans++;
            int min_sum = INT_MAX;
            int pos = -1;
            for (int i = 1; i < n; ++i) {
                int current_sum = arr[i - 1] + arr[i];
                if (current_sum < min_sum) {
                    min_sum = current_sum;
                    pos = i;
                }
            }
            arr[pos - 1] = min_sum;
            for (int i = pos; i < n - 1; ++i) {
                arr[i] = arr[i + 1];
            }
            n--;
        }

        return ans;
    }
};