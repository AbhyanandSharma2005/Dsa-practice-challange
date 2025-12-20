class Solution {
    public int minDeletionSize(String[] strs) {
        if (strs == null || strs.length == 0) return 0;
        int rows = strs.length;
        int cols = strs[0].length();
        int count = 0;
        
        for (int j = 0; j < cols; j++) {
            for (int i = 1; i < rows; i++) {
                if (strs[i].charAt(j) < strs[i-1].charAt(j)) {
                    count++;
                    break;
                }
            }
        }
        return count;
    }
}