class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.size();
        int ones = 0;
        for (char c : s) if (c == '1') ones++;
        if (ones == n) return n;
        vector<pair<int, int>> oneBlocks;
        int i = 0;
        while (i < n) {
            if (s[i] == '1') {
                int j = i;
                while (j < n && s[j] == '1') j++;
                bool leftZero = (i == 0 || s[i - 1] == '0');
                bool rightZero = (j == n || s[j] == '0');
                if (leftZero && rightZero) {
                    oneBlocks.push_back({i, j - 1});
                }
                i = j;
            } else {
                i++;
            }
        }
        if (oneBlocks.empty()) return ones;
        int best = ones;
        for (auto &block : oneBlocks) {
            int l = block.first, r = block.second;
            int leftZeros = 0;
            int leftIdx = l - 1;
            while (leftIdx >= 0 && s[leftIdx] == '0') {
                leftZeros++;
                leftIdx--;
            }
            int rightZeros = 0;
            int rightIdx = r + 1;
            while (rightIdx < n && s[rightIdx] == '0') {
                rightZeros++;
                rightIdx++;
            }
            if (leftZeros > 0 && rightZeros > 0) {
                best = max(best, ones + leftZeros + rightZeros);
            }
        }
        return min(best, n);
    }
};