class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        for(int a = 1; a < n; ++a) {
            int b = n - a;
            string sa = to_string(a), sb = to_string(b);
            if(sa.find('0') == string::npos && sb.find('0') == string::npos) return {a, b};
        }
        return {};
    }
};
