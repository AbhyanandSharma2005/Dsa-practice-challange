#include <vector>
#include <map>
#include <set>
using namespace std;

class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        vector<int> ans(n, -1);
        map<int, int> full;
        set<int> dry_days;
        for (int i = 0; i < n; ++i) {
            if (rains[i] == 0) {
                dry_days.insert(i);
                ans[i] = 1;
            } else {
                int lake = rains[i];
                if (full.count(lake)) {
                    auto it = dry_days.upper_bound(full[lake]);
                    if (it == dry_days.end()) return {};
                    ans[*it] = lake;
                    dry_days.erase(it);
                }
                full[lake] = i;
            }
        }
        return ans;
    }
};
