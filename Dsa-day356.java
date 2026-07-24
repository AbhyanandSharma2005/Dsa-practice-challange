class Solution {
    public int uniqueXorTriplets(int[] nums) {
        int n = nums.length;
        int size = 2048;
        while (size <= n) {
            size <<= 1;
        }
        int maxVal = 0;
        for (int x : nums) {
            maxVal = Math.max(maxVal, x);
        }
        int bits = 1;
        while ((1 << bits) <= maxVal) {
            bits++;
        }
        int limit = 1 << bits;

        boolean[] present = new boolean[limit];
        for (int x : nums) {
            present[x] = true;
        }

        int[] uniqueVals = new int[limit];
        int uCount = 0;
        for (int v = 0; v < limit; v++) {
            if (present[v]) {
                uniqueVals[uCount++] = v;
            }
        }

        boolean[] pairXor = new boolean[limit];
        for (int i = 0; i < uCount; i++) {
            for (int j = i; j < uCount; j++) {
                pairXor[uniqueVals[i] ^ uniqueVals[j]] = true;
            }
        }

        boolean[] tripleXor = new boolean[limit];
        for (int p = 0; p < limit; p++) {
            if (pairXor[p]) {
                for (int i = 0; i < uCount; i++) {
                    tripleXor[p ^ uniqueVals[i]] = true;
                }
            }
        }

        int count = 0;
        for (int v = 0; v < limit; v++) {
            if (tripleXor[v]) {
                count++;
            }
        }
        return count;
    }
}