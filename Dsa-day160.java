class Solution {
    public int minimumBoxes(int[] apple, int[] capacity) {
        int total = 0;
        for (int a : apple) {
            total += a;
        }
        Integer[] cap = new Integer[capacity.length];
        for (int i = 0; i < capacity.length; i++) {
            cap[i] = capacity[i];
        }
        java.util.Arrays.sort(cap, java.util.Comparator.reverseOrder());
        int sum = 0;
        for (int i = 0; i < cap.length; i++) {
            sum += cap[i];
            if (sum >= total) {
                return i + 1;
            }
        }
        return capacity.length;
    }
}