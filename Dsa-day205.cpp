class Solution {
public:
    int minimumDeletions(string s) {
        int min_deletions = 0;
        int b_count = 0;
        
        for (char c : s) {
            if (c == 'b') {
                b_count++;
            } else {  // c == 'a'
                // Either delete this 'a' or delete all previous 'b's
                min_deletions = min(min_deletions + 1, b_count);
            }
        }
        
        return min_deletions;
    }
};