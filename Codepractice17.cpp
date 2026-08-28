#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        int gt = 0, lt = 0;
        for (int j = i + 1; j < n; ++j) {
            if (a[j] > a[i]) {
                gt++;
            } else if (a[j] < a[i]) {
                lt++;
            }
        }
        cout << max(gt, lt) << (i == n - 1 ? "" : " ");
    }
    cout << "\n";
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