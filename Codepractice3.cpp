#include <iostream>
#include <vector>

using namespace std;

void solve() {
    long long n, d;
    cin >> n >> d;
    vector<long long> a(n);
    for (long long i = 0; i < n; ++i) {
        cin >> a[i];
    }

    long long current_S = 0;
    for (long long j = -d; j <= d; ++j) {
        long long idx = (j % n + n) % n;
        current_S += a[idx];
    }

    long long W = 2LL * d + 1;
    long long ans = 0;
    
    for (long long i = 0; i < n; ++i) {
        long long C = W * a[i] - current_S;
        if (C > 0) {
            ans += C;
        }
        
        long long remove_idx = ((i - d) % n + n) % n;
        long long add_idx = ((i + d + 1) % n + n) % n;
        current_S = current_S - a[remove_idx] + a[add_idx];
    }

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}