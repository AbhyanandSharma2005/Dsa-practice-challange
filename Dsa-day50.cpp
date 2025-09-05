class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        for (long long k = 1; k <= 60; ++k) {
            long long t = (long long)num1 - k * (long long)num2;
            if (t < k) {
                if (num2 >= 0) return -1;
                continue;
            }
            if (t >= 0 && __builtin_popcountll(t) <= k) return (int)k;
        }
        return -1;
    }
};
