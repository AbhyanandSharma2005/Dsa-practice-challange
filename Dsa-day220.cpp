class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int total = 1 << k;
        int n = s.length();
        if (n < k || n - k + 1 < total) return false;
        unordered_set<string> set;
        for (int i = 0; i <= n - k; i++) {
            set.insert(s.substr(i, k));
            if (set.size() == total) return true;
        }
        return set.size() == total;
    }
};