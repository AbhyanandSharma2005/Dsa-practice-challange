class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int first[26], last[26];
        fill(begin(first), end(first), -1);
        fill(begin(last), end(last), -1);

        for (int i = 0; i < s.size(); ++i) {
            int idx = s[i] - 'a';
            if (first[idx] == -1) {
                first[idx] = i;
            }
            last[idx] = i;
        }

        int result = 0;

        for (int i = 0; i < 26; ++i) {
            if (first[i] != -1 && last[i] > first[i] + 1) {
                int mask = 0;
                for (int j = first[i] + 1; j < last[i]; ++j) {
                    mask |= 1 << (s[j] - 'a');
                }
                
                result += __builtin_popcount(mask);
            }
        }

        return result;
    }
};
