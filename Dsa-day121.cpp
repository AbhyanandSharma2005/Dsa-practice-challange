class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        std::vector<int> pre(n + 1);
        pre[0] = -1;
        for (int i = 0; i < n; ++i) {
            if (i == 0 || (i > 0 && s[i - 1] == '0')) pre[i + 1] = i;
            else pre[i + 1] = pre[i];
        }
        int output = 0;
        for (int i = 1; i <= n; ++i) {
            int zeros = s[i - 1] == '0';
            int j = i;
            while (j > 0 && zeros * zeros <= n) {
                int ones = (i - pre[j]) - zeros;
                if (zeros * zeros <= ones) {
                    output += std::min(j - pre[j], ones - zeros * zeros + 1);
                }
                j = pre[j];
                ++zeros;
            }
        }
        return output;
    }
};