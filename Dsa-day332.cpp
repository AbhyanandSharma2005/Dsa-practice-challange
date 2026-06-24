class Solution {
    static constexpr int p = 1e9 + 7;
public:
    int zigZagArrays(int n, int l, int r) {
        int k = r - l + 1;

        unsigned mat[k][k];
        memset(mat, 0, sizeof(mat));
        for (int i = 0; i < k; ++i)
            for (int j = 0; j < i; ++j)
                mat[k - j - 1][i] = 1;

        unsigned res[k];
        for (int i = 0; i < k; ++i) res[i] = 1;

        int pw = n - 1;
        while (pw > 0) {
            if (pw & 1) {
                unsigned tmp[k];
                memset(tmp, 0, sizeof(tmp));
                for (int j = 0; j < k; ++j)
                    for (int l = 0; l < k; ++l)
                        tmp[j] = (tmp[j] + 1ULL * res[l] * mat[l][j]) % p;
                memcpy(res, tmp, sizeof(tmp));
            }
            unsigned tmp[k][k];
            memset(tmp, 0, sizeof(tmp));
            for (int i = 0; i < k; ++i)
                for (int l = 0; l < k; ++l) {
                    if (!mat[i][l]) continue;          
                    for (int j = 0; j < k; ++j)
                        tmp[i][j] = (tmp[i][j] + 1ULL * mat[i][l] * mat[l][j]) % p;
                }
            memcpy(mat, tmp, sizeof(tmp));
            pw >>= 1;
        }

        unsigned ret = 0;
        for (int i = 0; i < k; ++i) ret = (ret + res[i]) % p;
        return 2ULL * ret % p;
    }
};