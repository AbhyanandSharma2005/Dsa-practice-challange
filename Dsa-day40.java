class Solution {
    public int areaOfMaxDiagonal(int[][] dimensions) {
        int maxDiag = 0, maxArea = 0;

        for (int[] d : dimensions) {
            int l = d[0], w = d[1];
            int diagSq = l * l + w * w;
            int area = l * w;

            if (diagSq > maxDiag) {
                maxDiag = diagSq;
                maxArea = area;
            } else if (diagSq == maxDiag) {
                maxArea = Math.max(maxArea, area);
            }
        }

        return maxArea;
    }
}
