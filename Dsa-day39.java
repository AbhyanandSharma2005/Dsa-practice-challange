import java.util.*;

class Solution {
    public int[] findDiagonalOrder(int[][] mat) {
        if (mat == null || mat.length == 0) return new int[0];
        int m = mat.length, n = mat[0].length;
        ArrayList<Integer> result = new ArrayList<>();

        for (int diag = 0; diag < m + n - 1; diag++) {
            ArrayList<Integer> intermediate = new ArrayList<>();
            int r = diag < n ? 0 : diag - n + 1;
            int c = diag < n ? diag : n - 1;

            while (r < m && c >= 0) {
                intermediate.add(mat[r++][c--]);
            }

            if (diag % 2 == 0) {
                Collections.reverse(intermediate);
            }
            result.addAll(intermediate);
        }

        int[] resArr = new int[result.size()];
        for (int i = 0; i < result.size(); i++) {
            resArr[i] = result.get(i);
        }
        return resArr;
    }
}
