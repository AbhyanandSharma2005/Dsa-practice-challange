#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    bool judgePoint24(vector<int>& nums) {
        vector<double> numbers(nums.begin(), nums.end());
        return solve(numbers);
    }

private:
    bool solve(vector<double>& nums) {
        if (nums.size() == 1)
            return fabs(nums[0] - 24.0) < 1e-6;

        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                vector<double> nextNums;
                for (int k = 0; k < nums.size(); k++) {
                    if (k != i && k != j) {
                        nextNums.push_back(nums[k]);
                    }
                }
                vector<double> possibilities = computeResults(nums[i], nums[j]);

                for (double val : possibilities) {
                    nextNums.push_back(val);
                    if (solve(nextNums)) return true;
                    nextNums.pop_back();
                }
            }
        }
        return false;
    }

    vector<double> computeResults(double a, double b) {
        vector<double> results;
        results.push_back(a + b);
        results.push_back(a - b);
        results.push_back(b - a);
        results.push_back(a * b);
        if (fabs(b) > 1e-6) results.push_back(a / b);
        if (fabs(a) > 1e-6) results.push_back(b / a);
        return results;
    }
};
