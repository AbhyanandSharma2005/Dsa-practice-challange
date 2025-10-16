class Solution {
    public int findSmallestInteger(int[] nums, int value) {
        HashMap<Integer, Integer> freq = new HashMap<>();
        for (int x : nums) {
            int r = ((x % value) + value) % value;
            freq.put(r, freq.getOrDefault(r, 0) + 1);
        }
        int i = 0;
        while (true) {
            int r = i % value;
            if (!freq.containsKey(r) || freq.get(r) == 0) return i;
            freq.put(r, freq.get(r) - 1);
            i++;
        }
    }
}
