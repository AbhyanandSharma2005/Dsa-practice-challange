#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n, k;
    long long p, q;
    cin >> n >> k >> p >> q;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    if (k == n) {
        long long sum0 = 0, sum1 = 0, sum2 = 0, sum3 = 0;
        for (long long x : a) {
            sum0 += x;
            sum1 += (x % p);
            sum2 += (x % q);
            sum3 += ((x % q) % p);
        }
        cout << min({sum0, sum1, sum2, sum3}) << "\n";
    } else {
        long long ans = 0;
        for (long long x : a) {
            long long v0 = x;
            long long v1 = x % p;
            long long v2 = x % q;
            long long v3 = (x % q) % p;
            ans += min({v0, v1, v2, v3});
        }
        cout << ans << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}