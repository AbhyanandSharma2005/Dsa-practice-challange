#include <vector>
#include <numeric> 

class Solution {
public:
    long long gcd(long long a, long long b) {
        while (b) {
            a %= b;
            std::swap(a, b);
        }
        return a;
    }

    long long lcm(long long a, long long b) {
        if (a == 0 || b == 0) return 0;
        return (a * b) / gcd(a, b);
    }

    std::vector<int> replaceNonCoprimes(std::vector<int>& nums) {
        std::vector<int> result;
        for (int num : nums) {
            while (!result.empty() && gcd(num, result.back()) > 1) {
                int lastNum = result.back();
                result.pop_back();
                num = (int)lcm(num, lastNum);
            }
            result.push_back(num);
        }
        return result;
    }
};