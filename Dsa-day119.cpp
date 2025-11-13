class Solution {
public:
    int maxOperations(string s) {
        int count = 0, oneC = 0;
        for (int i = 0; i < s.size() - 1; ++i) {
            if (s[i] == '1') oneC++;
            if (s[i] == '1' && s[i + 1] == '0') count += oneC;
        }
        return count;
    }
};
