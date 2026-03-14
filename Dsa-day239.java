class Solution {
    private int count = 0;    
    private String result = ""; 
    private int target;
    private int n;

    public String getHappyString(int n, int k) {
        this.n = n;
        this.target = k;
        backtrack(new StringBuilder());
        return result;
    }
    
    private void backtrack(StringBuilder sb) {
        if (sb.length() == n) { 
            count++;
            if (count == target) { 
                result = sb.toString();
            }
            return;
        }
        
        for (char ch : new char[]{'a', 'b', 'c'}) {
            if (sb.length() == 0 || sb.charAt(sb.length() - 1) != ch) {
                sb.append(ch);
                backtrack(sb);
                if (!result.isEmpty()) { 
                    return;
                }
                sb.deleteCharAt(sb.length() - 1); 
            }
        }
    }
}
