class Solution {
    public boolean reorderedPowerOf2(int n) {
        String sortedN = sortDigits(n);
        for (int i = 0; i < 31; i++) {
            if (sortedN.equals(sortDigits(1 << i))) return true;
        }
        return false;
    }
    private String sortDigits(int num) {
        char[] arr = String.valueOf(num).toCharArray();
        java.util.Arrays.sort(arr);
        return new String(arr);
    }
}
