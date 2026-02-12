class Solution {
public:
    int longestBalanced(string s) {
        int n = s.length();
        int maxLen = 0;
        
        for (int i = 0; i < n; i++) {
            vector<int> freq(26, 0);
            for (int j = i; j < n; j++) {
                freq[s[j] - 'a']++;
                
                if (isBalanced(freq)) {
                    maxLen = max(maxLen, j - i + 1);
                }
            }
        }
        
        return maxLen;
    }
    
private:
    bool isBalanced(vector<int>& freq) {
        int count = -1;
        for (int f : freq) {
            if (f > 0) {
                if (count == -1) {
                    count = f;
                } else if (count != f) {
                    return false;
                }
            }
        }
        return true;
    }
};