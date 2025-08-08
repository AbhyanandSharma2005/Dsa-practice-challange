#include <bits/stdc++.h>
using namespace std;
class Solution {
    map<pair<int,int>, double> memo;
public:
    double soupServings(int n) {
        if (n >= 4800) return 1.0;
        int m = (n + 24) / 25;
        return dp(m, m);
    }
    double dp(int a, int b) {
        if (a <= 0 && b <= 0) return 0.5;
        if (a <= 0) return 1.0;
        if (b <= 0) return 0.0;
        auto key = make_pair(a, b);
        if (memo.count(key)) return memo[key];
        double res = 0.25 * (dp(a - 4, b) + dp(a - 3, b - 1) + dp(a - 2, b - 2) + dp(a - 1, b - 3));
        return memo[key] = res;
    }
};
