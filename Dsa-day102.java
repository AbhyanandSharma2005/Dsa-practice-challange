class Solution {
    public int numberOfBeams(String[] bank) {
        int prev = 0, res = 0;
        for (String row : bank) {
            int count = 0;
            for (char c : row.toCharArray()) if (c == '1') count++;
            if (count > 0) {
                res += prev * count;
                prev = count;
            }
        }
        return res;
    }
}
