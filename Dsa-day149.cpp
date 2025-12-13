class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        unordered_map<string, int> order = {
            {"electronics", 0},
            {"grocery", 1},
            {"pharmacy", 2},
            {"restaurant", 3}
        };
        vector<pair<int, string>> candidates;
        int n = code.size();
        for (int i = 0; i < n; ++i) {
            const string& c = code[i];
            const string& bl = businessLine[i];
            if (!c.empty() && isActive[i] && order.count(bl)) {
                bool valid_code = true;
                for (char ch : c) {
                    if (!isalnum(ch) && ch != '_') {
                        valid_code = false;
                        break;
                    }
                }
                if (valid_code) {
                    candidates.emplace_back(order[bl], c);
                }
            }
        }
        sort(candidates.begin(), candidates.end());
        vector<string> result;
        for (const auto& p : candidates) {
            result.push_back(p.second);
        }
        return result;
    }
};