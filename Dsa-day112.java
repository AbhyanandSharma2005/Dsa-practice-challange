import java.util.*;

class Solution {
    public int[] processQueries(int c, int[][] connections, int[][] queries) {
        boolean[] online = new boolean[c + 1];
        Arrays.fill(online, true);
        List<List<Integer>> adj = new ArrayList<>();
        for (int i = 0; i <= c; i++) adj.add(new ArrayList<>());
        for (int[] e : connections) {
            adj.get(e[0]).add(e[1]);
            adj.get(e[1]).add(e[0]);
        }

        List<PriorityQueue<Integer>> substations = new ArrayList<>();
        Map<Integer, Integer> stationLookup = new HashMap<>();

        class DFS {
            void run(int node, int idx) {
                if (stationLookup.containsKey(node)) return;
                stationLookup.put(node, idx);
                substations.get(idx).offer(node);
                for (int nei : adj.get(node)) run(nei, idx);
            }
        }

        DFS dfs = new DFS();
        for (int i = 1; i <= c; i++) {
            if (!stationLookup.containsKey(i)) {
                substations.add(new PriorityQueue<>());
                dfs.run(i, substations.size() - 1);
            }
        }

        List<Integer> result = new ArrayList<>();
        for (int[] q : queries) {
            int t = q[0], x = q[1];
            int sid = stationLookup.get(x);
            PriorityQueue<Integer> pq = substations.get(sid);

            if (t == 2) {
                online[x] = false;
                while (!pq.isEmpty() && !online[pq.peek()]) pq.poll();
            } else {
                if (online[x]) result.add(x);
                else {
                    while (!pq.isEmpty() && !online[pq.peek()]) pq.poll();
                    result.add(pq.isEmpty() ? -1 : pq.peek());
                }
            }
        }

        return result.stream().mapToInt(i -> i).toArray();
    }
}
