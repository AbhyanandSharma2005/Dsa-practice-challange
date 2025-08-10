class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string sortedN = sortDigits(n);
        for (int i = 0; i < 31; i++) {
            if (sortedN == sortDigits(1 << i)) return true;
        }
        return false;
    }
private:
    string sortDigits(int num) {
        string s = to_string(num);
        sort(s.begin(), s.end());
        return s;
    }
};
