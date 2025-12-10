class Solution {
public:
    int countPermutations(vector<int>& complexity) {
        int n = complexity.size();
        if (n == 1) return 1;
        long long c0 = complexity[0];
        for (int i = 1; i < n; ++i) {
            if (complexity[i] <= c0) return 0;
        }
        const int MOD = 1000000007;
        long long res = 1;
        for (int i = 2; i < n; ++i) {
            res = res * i % MOD;
        }
        return res;
    }
};