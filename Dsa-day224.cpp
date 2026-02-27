class Solution {
public:
    int minOperations(string s, int k) {
        int n = s.length();
        int initial_zeros = 0;
        for (char c : s) if (c == '0') initial_zeros++;

        if (initial_zeros == 0) return 0;

        set<int> unvisited[2];
        for (int i = 0; i <= n; ++i) {
            unvisited[i % 2].insert(i);
        }

        queue<pair<int, int>> q;
        q.push({initial_zeros, 0});
        unvisited[initial_zeros % 2].erase(initial_zeros);

        while (!q.empty()) {
            auto [cur, ops] = q.front();
            q.pop();

            int min_x = max(0, k - (n - cur));
            int max_x = min(k, cur);

            int L = cur + k - 2 * max_x;
            int R = cur + k - 2 * min_x;

            auto& s_set = unvisited[L % 2];
            auto it = s_set.lower_bound(L);
            
            while (it != s_set.end() && *it <= R) {
                int next_zeros = *it;
                if (next_zeros == 0) return ops + 1;
                
                q.push({next_zeros, ops + 1});
                it = s_set.erase(it);
            }
        }

        return -1;
    }
};