#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (cin >> t) {
        while (t--) {
            long long n, m;
            cin >> n >> m;
            
            long long a1 = 0, b1 = 0, temp;
            
            for (int i = 0; i < n; ++i) {
                cin >> temp;
                if (i == 0) a1 = temp;
            }
            
            for (int i = 0; i < m; ++i) {
                cin >> temp;
                if (i == 0) b1 = temp;
            }
            
            if (a1 + n >= b1 + m) {
                cout << 1 << "\n";
            } else {
                cout << 2 << "\n";
            }
        }
    }
    return 0;
