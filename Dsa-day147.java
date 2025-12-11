class Solution {
    public int countCoveredBuildings(int n, int[][] buildings) {
        Map<Integer, List<Integer>> rows = new HashMap<>();
        Map<Integer, List<Integer>> cols = new HashMap<>();
        
        for (int[] b : buildings) {
            int x = b[0], y = b[1];
            rows.computeIfAbsent(x, k -> new ArrayList<>()).add(y);
            cols.computeIfAbsent(y, k -> new ArrayList<>()).add(x);
        }
        
        for (List<Integer> list : rows.values()) Collections.sort(list);
        for (List<Integer> list : cols.values()) Collections.sort(list);
        
        int ans = 0;
        for (int[] b : buildings) {
            int x = b[0], y = b[1];
            
            List<Integer> rowY = rows.get(x);
            boolean hasLeft  = rowY.get(0) < y;
            boolean hasRight = rowY.get(rowY.size() - 1) > y;
            
            List<Integer> colX = cols.get(y);
            boolean hasAbove = colX.get(0) < x;
            boolean hasBelow = colX.get(colX.size() - 1) > x;
            
            if (hasLeft && hasRight && hasAbove && hasBelow) ans++;
        }
        return ans;
    }
}