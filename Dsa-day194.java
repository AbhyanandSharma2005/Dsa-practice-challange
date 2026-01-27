class Solution {
    public int minCost(int n, int[][] edges) {
        List<List<int[]>> outgoing = new ArrayList<>();
        List<List<int[]>> incoming = new ArrayList<>();
        
        for (int i = 0; i < n; i++) {
            outgoing.add(new ArrayList<>());
            incoming.add(new ArrayList<>());
        }
        
        for (int[] e : edges) {
            int u = e[0], v = e[1], w = e[2];
            outgoing.get(u).add(new int[]{v, w});
            incoming.get(v).add(new int[]{u, w});
        }
        
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> Integer.compare(a[0], b[0]));
        pq.offer(new int[]{0, 0, 0});
        
        Set<String> visited = new HashSet<>();
        
        while (!pq.isEmpty()) {
            int[] curr = pq.poll();
            int cost = curr[0];
            int node = curr[1];
            int switchUsed = curr[2];
            
            if (node == n - 1) {
                return cost;
            }
            
            String state = node + "," + switchUsed;
            if (visited.contains(state)) {
                continue;
            }
            visited.add(state);
            
            for (int[] edge : outgoing.get(node)) {
                int neighbor = edge[0];
                int weight = edge[1];
                String newState = neighbor + ",0";
                if (!visited.contains(newState)) {
                    pq.offer(new int[]{cost + weight, neighbor, 0});
                }
            }
            
            if (switchUsed == 0) {
                for (int[] edge : incoming.get(node)) {
                    int prevNode = edge[0];
                    int weight = edge[1];
                    String newState = prevNode + ",0";
                    if (!visited.contains(newState)) {
                        pq.offer(new int[]{cost + 2 * weight, prevNode, 0});
                    }
                }
            }
        }
        
        return -1;
    }
}