class Solution {
    public int maxActiveSectionsAfterTrade(String s) {
        int n = s.length();
        int ones = 0;
        for (char c : s.toCharArray()) if (c == '1') ones++;
        if (ones == n) return n;
        
        List<int[]> oneBlocks = new ArrayList<>();
        int i = 0;
        while (i < n) {
            if (s.charAt(i) == '1') {
                int j = i;
                while (j < n && s.charAt(j) == '1') j++;
                boolean leftZero = (i == 0 || s.charAt(i - 1) == '0');
                boolean rightZero = (j == n || s.charAt(j) == '0');
                if (leftZero && rightZero) {
                    oneBlocks.add(new int[]{i, j - 1});
                }
                i = j;
            } else {
                i++;
            }
        }
        
        if (oneBlocks.isEmpty()) return ones;
        
        int best = ones;
        for (int[] block : oneBlocks) {
            int l = block[0], r = block[1];
            int blockLen = r - l + 1;
            
            int leftZeros = 0;
            int leftIdx = l - 1;
            while (leftIdx >= 0 && s.charAt(leftIdx) == '0') {
                leftZeros++;
                leftIdx--;
            }
            
            int rightZeros = 0;
            int rightIdx = r + 1;
            while (rightIdx < n && s.charAt(rightIdx) == '0') {
                rightZeros++;
                rightIdx++;
            }
            
            int gain = leftZeros + rightZeros;
            
            if (leftZeros > 0 && rightZeros > 0) {
                best = Math.max(best, ones + gain);
            }
        }
        
        return Math.min(best, n);
    }
}