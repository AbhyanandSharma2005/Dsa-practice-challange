#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        vector<int> counts(26, 0);
        for (char c : s) {
            counts[c - 'a']++;
        }
        
        int odd_count = 0;
        string mid = "";
        vector<int> half_counts(26, 0);
        for (int i = 0; i < 26; ++i) {
            if (counts[i] % 2 != 0) {
                odd_count++;
                mid = string(1, 'a' + i);
            }
            half_counts[i] = counts[i] / 2;
        }
        
        if (odd_count > 1) {
            return "";
        }
        
        int L = s.length() / 2;
        string H_prefix = "";
        
        for (int i = 0; i < L; ++i) {
            bool found = false;
            for (int c = 0; c < 26; ++c) {
                if (half_counts[c] > 0) {
                    half_counts[c]--;
                    
                    string H = H_prefix + (char)('a' + c);
                    for (int k = 25; k >= 0; --k) {
                        if (half_counts[k] > 0) {
                            H += string(half_counts[k], 'a' + k);
                        }
                    }
                    
                    string P = H + mid;
                    string rev_H = H;
                    reverse(rev_H.begin(), rev_H.end());
                    P += rev_H;
                    
                    if (P > target) {
                        H_prefix += (char)('a' + c);
                        found = true;
                        break;
                    }
                    
                    half_counts[c]++;
                }
            }
            if (!found) {
                return "";
            }
        }
        
        string ans = H_prefix + mid;
        string rev_H = H_prefix;
        reverse(rev_H.begin(), rev_H.end());
        ans += rev_H;
        
        return ans > target ? ans : "";
    }
};