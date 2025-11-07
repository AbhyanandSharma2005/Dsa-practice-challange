class Solution {
public:
    long long maxPower(vector<int>& stations, int r, int k) {
        int n = stations.size();
        vector<long long> power(n, 0), prefix(n + 1, 0);
        for (int i = 0; i < n; ++i) prefix[i + 1] = prefix[i] + stations[i];
        for (int i = 0; i < n; ++i) {
            int left = max(0, i - r), right = min(n - 1, i + r);
            power[i] = prefix[right + 1] - prefix[left];
        }
        auto can = [&](long long mid) {
            vector<long long> added(n + 1, 0);
            long long total_add = 0, used = 0;
            for (int i = 0; i < n; ++i) {
                total_add += added[i];
                if (power[i] + total_add < mid) {
                    long long need = mid - (power[i] + total_add);
                    if (used + need > k) return false;
                    used += need;
                    total_add += need;
                    if (i + 2 * r + 1 < n) added[i + 2 * r + 1] -= need;
                }
            }
            return true;
        };
        long long left = 0, right = accumulate(stations.begin(), stations.end(), 0LL) + k, ans = 0;
        while (left <= right) {
            long long mid = (left + right) / 2;
            if (can(mid)) ans = mid, left = mid + 1;
            else right = mid - 1;
        }
        return ans;
    }
};
