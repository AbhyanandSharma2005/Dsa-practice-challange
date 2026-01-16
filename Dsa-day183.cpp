#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        const long long MOD = 1e9 + 7;

        vector<int> h = {1, m};
        vector<int> v = {1, n};

        for (int x : hFences) h.push_back(x);
        for (int x : vFences) v.push_back(x);

        sort(h.begin(), h.end());
        sort(v.begin(), v.end());

        unordered_set<int> hs;
        for (int i = 0; i < h.size(); i++)
            for (int j = i + 1; j < h.size(); j++)
                hs.insert(h[j] - h[i]);

        long long ans = -1;
        for (int i = 0; i < v.size(); i++)
            for (int j = i + 1; j < v.size(); j++) {
                int d = v[j] - v[i];
                if (hs.count(d)) ans = max(ans, (long long)d);
            }

        if (ans == -1) return -1;
        return (ans * ans) % MOD;
    }
};
