#include <vector>

class Solution {
public:
    int missingInteger(std::vector<int>& nums) {
        int sum = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == nums[i - 1] + 1) {
                sum += nums[i];
            } else {
                break;
            }
        }
        
        while (true) {
            bool found = false;
            for (int num : nums) {
                if (num == sum) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                return sum;
            }
            sum++;
        }
    }
};