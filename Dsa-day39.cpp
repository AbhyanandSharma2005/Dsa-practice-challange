#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        if(mat.empty() || mat[0].empty()) return {};
        int m = mat.size(), n = mat[0].size();
        vector<int> result;
        vector<int> intermediate;

        for (int diag = 0; diag < m + n - 1; ++diag) {
            intermediate.clear();
            int r = diag < n ? 0 : diag - n + 1;
            int c = diag < n ? diag : n - 1;

            while (r < m && c >= 0) {
                intermediate.push_back(mat[r++][c--]);
            }

            if (diag % 2 == 0) {
                reverse(intermediate.begin(), intermediate.end());
            }

            result.insert(result.end(), intermediate.begin(), intermediate.end());
        }

        return result;
    }
};
