class Solution {
    public int numberOfPairs(int[][] points) {
        int n = points.length;
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) {
                    continue;
                }
                int x1 = points[i][0];
                int y1 = points[i][1];
                int x2 = points[j][0];
                int y2 = points[j][1];
                if (x1 <= x2 && y1 >= y2) {
                    boolean isEmpty = true;
                    for (int k = 0; k < n; k++) {
                        if (k == i || k == j) {
                            continue;
                        }
                        int x3 = points[k][0];
                        int y3 = points[k][1];
                        if (x1 <= x3 && x3 <= x2 && y2 <= y3 && y3 <= y1) {
                            isEmpty = false;
                            break;
                        }
                    }
                    if (isEmpty) {
                        count++;
                    }
                }
            }
        }
        return count;
    }
}