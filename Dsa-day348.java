class Solution {
    public int countCompleteComponents(int n, int[][] edges) {
        List<List<Integer>> adj = new ArrayList<>();
        boolean[] visited = new boolean[n];
        for (int i = 0; i < n; i++) {
            adj.add(new ArrayList<>());
        }
        for (int[] edge : edges) {
            adj.get(edge[0]).add(edge[1]);
            adj.get(edge[1]).add(edge[0]);
        }
        int completeComponents = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                List<Integer> component = new ArrayList<>();
                int edgeCount = dfs(i, visited, adj, component);

                int size = component.size();
                if (edgeCount == (size * (size - 1)) / 2) {
                    completeComponents++;
                }
            }
        }
        return completeComponents;
    }

    private int dfs(int node, boolean[] visited, List<List<Integer>> adj, List<Integer> component) {
        Stack<Integer> stack = new Stack<>();
        stack.push(node);
        visited[node] = true;
        
        int edgeCount = 0;
        component.add(node);

        while (!stack.isEmpty()) {
            int curr = stack.pop();
            
            for (int neighbor : adj.get(curr)) {
                edgeCount++; // Counting each edge once
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    stack.push(neighbor);
                    component.add(neighbor);
                }
            }
        }

        return edgeCount / 2; // Since each edge is counted twice
    }
}