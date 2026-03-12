#include <vector>
#include <algorithm>

using namespace std;

struct DSU {
    vector<int> parent;
    int components;
    DSU(int n) : components(n) {
        parent.resize(n);
        for (int i = 0; i < n; ++i) parent[i] = i;
    }
    int find(int i) {
        if (parent[i] == i) return i;
        return parent[i] = find(parent[i]);
    }
    bool unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) {
            parent[root_i] = root_j;
            components--;
            return true;
        }
        return false;
    }
};

class Solution {
public:
    int maxStability(int n, vector<vector<int>>& edges, int k) {
        // Pre-check: Mandatory edges must not form a cycle
        DSU check_mandatory(n);
        int mandatory_count = 0;
        for (const auto& e : edges) {
            if (e[3] == 1) {
                if (!check_mandatory.unite(e[0], e[1])) return -1; // Cycle
                mandatory_count++;
            }
        }

        auto can_achieve = [&](int X) {
            DSU dsu(n);
            int upgrades_used = 0;
            // 1. Mandatory edges
            for (const auto& e : edges) {
                if (e[3] == 1) {
                    if (e[2] < X) return false;
                    dsu.unite(e[0], e[1]);
                }
            }
            // 2. Free optional edges
            for (const auto& e : edges) {
                if (e[3] == 0 && e[2] >= X) {
                    dsu.unite(e[0], e[1]);
                }
            }
            for (const auto& e : edges) {
                if (e[3] == 0 && e[2] < X && e[2] * 2 >= X) {
                    if (dsu.find(e[0]) != dsu.find(e[1])) {
                        if (upgrades_used < k) {
                            dsu.unite(e[0], e[1]);
                            upgrades_used++;
                        }
                    }
                }
            }
            return dsu.components == 1;
        };

        int low = 1, high = 200000, ans = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (can_achieve(mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};