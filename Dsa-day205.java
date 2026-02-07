class Solution {
    public int minimumDeletions(String s) {
        int minDeletions = 0;
        int bCount = 0;
        
        for (char c : s.toCharArray()) {
            if (c == 'b') {
                bCount++;
            } else {  // c == 'a'
                // Either delete this 'a' or delete all previous 'b's
                minDeletions = Math.min(minDeletions + 1, bCount);
            }
        }
        
        return minDeletions;
    }
}
