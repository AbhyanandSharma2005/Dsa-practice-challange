class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int result = 0;

        for (const auto& p : patterns) {
            if (word.find(p) != string::npos) {
                ++result;
            }
        }

        return result;
    }
};