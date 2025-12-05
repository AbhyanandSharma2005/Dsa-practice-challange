#include <vector>
#include <numeric> 
using namespace std;
class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        if (total % 2 != 0) {
            return 0;
        } else {
            return nums.size() - 1;
        }  }  };
