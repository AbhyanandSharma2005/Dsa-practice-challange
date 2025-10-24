#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int nextBeautifulNumber(int n) {
        unordered_set<int> s;
        for (int mask = 1; mask < (1 << 9); ++mask) {
            vector<char> digits;
            int total = 0;
            for (int i = 0; i < 9; ++i) {
                if (mask & (1 << i)) {
                    int d = i + 1;
                    total += d;
                    for (int j = 0; j < d; ++j) digits.push_back('0' + d);
                }
            }
            if (total == 0 || total > 7) continue;
            sort(digits.begin(), digits.end());
            do {
                if (digits[0] == '0') continue;
                int val = stoi(string(digits.begin(), digits.end()));
                s.insert(val);
            } while (next_permutation(digits.begin(), digits.end()));
        }
        vector<int> nums(s.begin(), s.end());
        sort(nums.begin(), nums.end());
        for (int x : nums) if (x > n) return x;
        return -1;
    }
};
