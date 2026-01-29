class Solution {
    public long minimumCost(String source, String target, char[] original, char[] changed, int[] cost) {
        long[][] dist = new long[26][26];
        
        for(int i = 0; i < 26; i++) {
            for(int j = 0; j < 26; j++) {
                if(i == j) {
                    dist[i][j] = 0;
                } else {
                    dist[i][j] = Long.MAX_VALUE;
                }
            }
        }
        
        for(int i = 0; i < cost.length; i++) {
            int u = original[i] - 'a';
            int v = changed[i] - 'a';
            dist[u][v] = Math.min(dist[u][v], cost[i]);
        }
        
        for(int k = 0; k < 26; k++) {
            for(int i = 0; i < 26; i++) {
                for(int j = 0; j < 26; j++) {
                    if(dist[i][k] != Long.MAX_VALUE && dist[k][j] != Long.MAX_VALUE) {
                        dist[i][j] = Math.min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }
        
        long totalCost = 0;
        
        for(int i = 0; i < source.length(); i++) {
            if(source.charAt(i) != target.charAt(i)) {
                int u = source.charAt(i) - 'a';
                int v = target.charAt(i) - 'a';
                
                if(dist[u][v] == Long.MAX_VALUE) {
                    return -1;
                }
                
                totalCost += dist[u][v];
            }
        }
        
        return totalCost;
    }
}