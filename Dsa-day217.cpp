class Solution {
public:
    string makeLargestSpecial(string s) {
        int count = 0, start = 0;
        vector<string> specials;
        for (int i = 0; i < s.size(); i++) {
            count += s[i] == '1' ? 1 : -1;
            if (count == 0) {
                specials.push_back("1" + makeLargestSpecial(s.substr(start + 1, i - start - 1)) + "0");
                start = i + 1;
            }
        }
        sort(specials.rbegin(), specials.rend());
        string res;
        for (auto& sp : specials) res += sp;
        return res;
    }
};