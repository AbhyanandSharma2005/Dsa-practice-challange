class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        vector<int> prefixY(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefixY[i + 1] = prefixY[i] + (customers[i] == 'Y' ? 1 : 0);
        }
        
        int minPenalty = INT_MAX;
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
};