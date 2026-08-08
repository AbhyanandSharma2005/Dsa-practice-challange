#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        
        // suf[i] will store the maximum length of a suffix of word2
        // that is a subsequence of word1[i...n-1].
        vector<int> suf(n + 1, 0);
        int j = m - 1;
        for (int i = n - 1; i >= 0; --i) {
            if (j >= 0 && word1[i] == word2[j]) {
                j--;
            }
            suf[i] = m - 1 - j;
        }
        
        vector<int> ans;
        j = 0;
        bool changed = false;
        
        for (int i = 0; i < n && j < m; ++i) {
            if (word1[i] == word2[j]) {
                // Exact match: always take it to minimize index and preserve the change
                ans.push_back(i);
                j++;
            } else if (!changed && suf[i + 1] >= m - j - 1) {
                // Can use the 1 allowed change here because the remaining characters
                // of word2 can be matched exactly in the remaining characters of word1.
                changed = true;
                ans.push_back(i);
                j++;
            }
        }
        
        // If we successfully mapped all characters of word2, return the sequence
        if (j == m) {
            return ans;
        }
        
        // Otherwise, no such valid sequence of indices exists
        return {};
    }
};