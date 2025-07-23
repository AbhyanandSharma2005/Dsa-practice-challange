class Solution {
    public int maximumGain(String s, int x, int y) {
        if (x > y) {
            int score = removePattern(s, 'a', 'b', x);
            s = remainingString; 
            return score + removePattern(s, 'b', 'a', y);
        } else {
            int score = removePattern(s, 'b', 'a', y);
            s = remainingString;
            return score + removePattern(s, 'a', 'b', x);
        }
    }

    String remainingString;

    private int removePattern(String s, char first, char second, int value) {
        StringBuilder sb = new StringBuilder();
        int score = 0;

        for (char c : s.toCharArray()) {
            if (sb.length() > 0 && sb.charAt(sb.length() - 1) == first && c == second) {
                sb.deleteCharAt(sb.length() - 1); 
                score += value;
            } else {
                sb.append(c);
            }
        }

        remainingString = sb.toString(); 
        return score;
    }
}
