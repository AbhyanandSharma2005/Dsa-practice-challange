class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        const int MOD = 1e9 + 7;
        vector<int> powers;
        int bit = 0, temp = n;
        while (temp > 0) {
            if (temp & 1) powers.push_back(1 << bit);
            bit++;
            temp >>= 1;
        }
        vector<long long> prefix(powers.size() + 1, 1);
        for (int i = 0; i < powers.size(); i++) {
            prefix[i+1] = (prefix[i] * powers[i]) % MOD;
        }
        vector<int> ans;
        for (auto& q : queries) {
            int l = q[0], r = q[1];
            long long prod = prefix[r+1] * modPow(prefix[l], MOD - 2, MOD) % MOD;
            ans.push_back((int)prod);
        }
        return ans;
    }
private:
    long long modPow(long long a, long long b, int mod) {
        long long res = 1;
        while (b > 0) {
            if (b & 1) res = (res * a) % mod;
            a = (a * a) % mod;
            b >>= 1;
        }
        return res;
    }
};
