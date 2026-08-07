#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
const long long INF = 1e18;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n;
    if (!(cin >> n)) return 0;
 
    vector<long long> m(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> m[i];
    }
 
    vector<bool> vis(n + 1, false);
    long long total_cost = 0;
 
    for (int c = 1; c <= n; ++c) {
        if (vis[c]) continue;
 
        vector<vector<long long>> grid;
        long long curr_y = c;
        while (curr_y <= n) {
            vector<long long> row;
            long long curr_x = curr_y;
            while (curr_x <= n) {
                row.push_back(m[curr_x]);
                vis[curr_x] = true;
                curr_x *= 2;
            }
            grid.push_back(row);
            curr_y *= 3;
        }
 
        int H = grid.size();
        if (H == 0) continue;
 
        int L0 = grid[0].size();
        vector<long long> dp_prev(1 << L0, 0);
        for (int mask = 0; mask < (1 << L0); ++mask) {
            long long cost = 0;
            for (int i = 0; i < L0; ++i) {
                if (mask & (1 << i)) {
                    cost += grid[0][i];
                }
            }
            dp_prev[mask] = cost;
        }
 
        for (int j = 1; j < H; ++j) {
            int L_prev = grid[j - 1].size();
            int L_curr = grid[j].size();
 
            vector<long long> best_req(1 << L_curr, INF);
 
            for (int P = 0; P < (1 << L_prev); ++P) {
                int R = 0;
                for (int i = 0; i <= L_prev - 3; ++i) {
                    if (!(P & (1 << i)) && !(P & (1 << (i + 1))) && !(P & (1 << (i + 2)))) {
                        R |= (1 << i);
                    }
                }
                if (best_req[R] > dp_prev[P]) {
                    best_req[R] = dp_prev[P];
                }
            }
 
            for (int i = 0; i < L_curr; ++i) {
                for (int mask = 0; mask < (1 << L_curr); ++mask) {
                    if (mask & (1 << i)) {
                        if (best_req[mask ^ (1 << i)] < best_req[mask]) {
                            best_req[mask] = best_req[mask ^ (1 << i)];
                        }
                    }
                }
            }
 
            vector<long long> dp_curr(1 << L_curr, 0);
            for (int mask = 0; mask < (1 << L_curr); ++mask) {
                long long cost = 0;
                for (int i = 0; i < L_curr; ++i) {
                    if (mask & (1 << i)) {
                        cost += grid[j][i];
                    }
                }
                dp_curr[mask] = cost + best_req[mask];
            }
            dp_prev = move(dp_curr);
        }
 
        long long min_comp = INF;
        for (long long val : dp_prev) {
            if (val < min_comp) {
                min_comp = val;
            }
        }
        total_cost += min_comp;
    }
 
    cout << total_cost << "\n";
    return 0;
}