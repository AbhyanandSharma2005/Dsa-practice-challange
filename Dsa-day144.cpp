class Solution {
public:
    int countTriples(int n) {
        vector<int> squares(n + 1);
        unordered_set<int> sq_set;
        for (int i = 1; i <= n; ++i) {
            squares[i] = i * i;
            sq_set.insert(squares[i]);
        }
        
        int count = 0;
        for (int a = 1; a <= n; ++a) {
            for (int b = 1; b <= n; ++b) {
                long long need = (long long)squares[a] + squares[b];
                if (sq_set.count(need)) {
                    int c = sqrt(need);
                    if (c * c == need && c <= n) {
                        ++count;
                    }
                }
            }
        }
        return count;
    }
};