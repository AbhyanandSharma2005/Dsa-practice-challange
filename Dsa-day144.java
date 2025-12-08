class Solution {
    public int countTriples(int n) {
        int[] squares = new int[n + 1];
        Set<Integer> sqSet = new HashSet<>();
        for (int i = 1; i <= n; i++) {
            squares[i] = i * i;
            sqSet.add(squares[i]);
        }
        
        int count = 0;
        for (int a = 1; a <= n; a++) {
            for (int b = 1; b <= n; b++) {
                long need = (long)squares[a] + squares[b];
                if (sqSet.contains((int)need)) {
                    int c = (int)Math.sqrt(need);
                    if (c * c == need && c <= n) {
                        count++;
                    }
                }
            }
        }
        return count;
    }
}