class Solution {
    public int maximizeSquareHoleArea(int n, int m, int[] hBars, int[] vBars) {
        int maxH = getMaxConsecutive(hBars);
        int maxV = getMaxConsecutive(vBars);
        int side = Math.min(maxH, maxV) + 1;
        return side * side;
    }
    
    private int getMaxConsecutive(int[] bars) {
        if (bars.length == 0) return 1;
        Arrays.sort(bars);
        int max = 1;
        int curr = 1;
        for (int i = 1; i < bars.length; i++) {
            if (bars[i] == bars[i - 1] + 1) {
                curr++;
                max = Math.max(max, curr);
            } else {
                curr = 1;
            }
        }
        return max;
    }
}