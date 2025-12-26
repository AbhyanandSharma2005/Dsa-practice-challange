class Solution {
    public int bestClosingTime(String customers) {
        int n = customers.length();
        int[] prefixY = new int[n + 1];
        for (int i = 0; i < n; i++) {
            prefixY[i + 1] = prefixY[i] + (customers.charAt(i) == 'Y' ? 1 : 0);
        }
        
        int minPenalty = Integer.MAX_VALUE;
        int bestHour = 0;
        int totalY = prefixY[n];
        
        for (int j = 0; j <= n; j++) {
            int openNoCust = j - prefixY[j];
            int closedWithCust = totalY - prefixY[j];
            int penalty = openNoCust + closedWithCust;
            
            if (penalty < minPenalty) {
                minPenalty = penalty;
                bestHour = j;
            }
        }
        return bestHour;
    }
}