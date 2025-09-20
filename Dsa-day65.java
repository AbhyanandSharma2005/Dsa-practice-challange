import java.util.*;

class Router {
    int limit;
    Deque<int[]> q;
    Set<String> seen;
    Map<Integer, ArrayList<Integer>> destMap;

    public Router(int memoryLimit) {
        limit = memoryLimit;
        q = new ArrayDeque<>();
        seen = new HashSet<>();
        destMap = new HashMap<>();
    }

    public boolean addPacket(int source, int destination, int timestamp) {
        String key = source + "," + destination + "," + timestamp;
        if (seen.contains(key)) return false;
        if (q.size() == limit) {
            int[] pkt = q.poll();
            seen.remove(pkt[0] + "," + pkt[1] + "," + pkt[2]);
            ArrayList<Integer> arr = destMap.get(pkt[1]);
            int idx = Collections.binarySearch(arr, pkt[2]);
            arr.remove(idx < 0 ? -idx - 1 : idx);
        }
        q.offer(new int[]{source, destination, timestamp});
        seen.add(key);
        destMap.putIfAbsent(destination, new ArrayList<>());
        ArrayList<Integer> arr = destMap.get(destination);
        int idx = Collections.binarySearch(arr, timestamp);
        if (idx < 0) idx = -idx - 1;
        arr.add(idx, timestamp);
        return true;
    }

    public int[] forwardPacket() {
        if (q.isEmpty()) return new int[]{};
        int[] pkt = q.poll();
        seen.remove(pkt[0] + "," + pkt[1] + "," + pkt[2]);
        ArrayList<Integer> arr = destMap.get(pkt[1]);
        int idx = Collections.binarySearch(arr, pkt[2]);
        arr.remove(idx < 0 ? -idx - 1 : idx);
        return pkt;
    }

    public int getCount(int destination, int startTime, int endTime) {
        ArrayList<Integer> arr = destMap.getOrDefault(destination, new ArrayList<>());
        int l = Collections.binarySearch(arr, startTime);
        if (l < 0) l = -l - 1;
        int r = Collections.binarySearch(arr, endTime);
        if (r < 0) r = -r - 2;
        else {
            while (r + 1 < arr.size() && arr.get(r + 1) == endTime) r++;
        }
        return r - l + 1 < 0 ? 0 : r - l + 1;
    }
}
