class Solution {
    public int minDeletionSize(String[] A) {
        if (A == null || A.length <= 1) {
            return 0;
        }
        int len = A.length, wordLen = A[0].length(), res = 0;
        boolean[] cut = new boolean[len];
    search:
        for (int j = 0; j < wordLen; j++) {
            for (int i = 0; i < len - 1; i++) {
                if (!cut[i] && A[i].charAt(j) > A[i + 1].charAt(j)) {
                    res += 1;
                    continue search;
                }
            }
            for (int i = 0; i < len - 1; i++) {
                if (A[i].charAt(j) < A[i + 1].charAt(j)) {
                    cut[i] = true;
                }
            }
        }
        return res;
    }
}