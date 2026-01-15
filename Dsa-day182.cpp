class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        int maxH = getMaxConsecutive(hBars);
        int maxV = getMaxConsecutive(vBars);
        int side = min(maxH, maxV) + 1;
        return side * side;
    }
    
private:
    int getMaxConsecutive(vector<int>& bars) {
        if (bars.empty()) return 1;
        sort(bars.begin(), bars.end());
        int maxLen = 1;
        int curr = 1;
        for (size_t i = 1; i < bars.size(); ++i) {
            if (bars[i] == bars[i - 1] + 1) {
                ++curr;
                maxLen = max(maxLen, curr);
            } else {
                curr = 1;
            }
        }
        return maxLen;
    }
};