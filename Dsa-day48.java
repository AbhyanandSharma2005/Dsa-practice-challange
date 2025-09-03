import java.util.Arrays;
import java.util.Comparator;

class Solution {
    public int numberOfPairs(int[][] points) {
        Arrays.sort(points, new Comparator<int[]>() {
            @Override
            public int compare(int[] a, int[] b) {
                if (a[0] != b[0]) {
                    return Integer.compare(a[0], b[0]);
                }
                return Integer.compare(b[1], a[1]);
            }
        });
        
        int n = points.length;
        int count = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (points[i][1] >= points[j][1]) {
                    boolean is_clear = true;
                    for (int k = i + 1; k < j; k++) {
                        if (points[j][1] <= points[k][1] && points[k][1] <= points[i][1]) {
                            is_clear = false;
                            break;
                        }
                    }
                    if (is_clear) {
                        count++;
                    }
                }
            }
        }
        
        return count;
    }
}