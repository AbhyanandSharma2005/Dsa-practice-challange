#define ll long long

class Solution {
public:
    long long maxSubarrays(int n, vector<vector<int>>& conflictingPairs) {
        vector<vector<int>> left(n + 1);
        for (auto el : conflictingPairs) {
            int a = min(el[0], el[1]);
            int b = max(el[0], el[1]);
            left[b].push_back(a);
        }

        ll ans = 0, rest1 = 0, rest2 = 0;
        vector<ll> pt(n + 1);
        for (int b = 1; b <= n; b++) {
            for (auto e : left[b]) {
                if (e > rest1) {
                    rest2 = rest1;
                    rest1 = e;
                } else if (e > rest2)
                    rest2 = e;
            }
            ans += b - rest1;

            if (rest1 > 0)
                pt[rest1] += (rest1 - rest2);
        }

        ll mx=0;
        for (auto vl : pt)
            mx = max(mx, vl);

        return ans + mx;
    }
};