class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        const int MOD = 1000000007;
        unordered_map<int, int> left, right;
        for (int x : nums) right[x]++;
        long long ans = 0;
        for (int x : nums) {
            right[x]--;
            long long target = 2LL * x;
            long long cnt_left = left[target];
            long long cnt_right = right[target];
            ans = (ans + cnt_left * cnt_right % MOD) % MOD;
            left[x]++;
        }
        return ans;
    }
};