import java.util.*;

class Solution {
    public long minCost(int[] basket1, int[] basket2) {
        Map<Integer, Integer> combinedFreq = new HashMap<>();
        long min_cost = Long.MAX_VALUE;

        for (int x : basket1) {
            combinedFreq.put(x, combinedFreq.getOrDefault(x, 0) + 1);
            min_cost = Math.min(min_cost, x);
        }
        for (int x : basket2) {
            combinedFreq.put(x, combinedFreq.getOrDefault(x, 0) + 1);
            min_cost = Math.min(min_cost, x);
        }

        List<Integer> misplaced = new ArrayList<>();
        Map<Integer, Integer> freq1 = new HashMap<>();
        for (int x : basket1) {
            freq1.put(x, freq1.getOrDefault(x, 0) + 1);
        }

        for (Map.Entry<Integer, Integer> entry : combinedFreq.entrySet()) {
            int fruit = entry.getKey();
            int totalCount = entry.getValue();
            if (totalCount % 2 != 0) {
                return -1;
            }
            int targetCount = totalCount / 2;
            int count1 = freq1.getOrDefault(fruit, 0);

            if (count1 > targetCount) {
                for (int i = 0; i < count1 - targetCount; i++) {
                    misplaced.add(fruit);
                }
            } else if (count1 < targetCount) {
                for (int i = 0; i < targetCount - count1; i++) {
                    misplaced.add(fruit);
                }
            }
        }

        Collections.sort(misplaced);
        
        long totalCost = 0;
        int k = misplaced.size() / 2;
        
        for (int i = 0; i < k; i++) {
            totalCost += Math.min(misplaced.get(i), min_cost * 2);
        }
        
        return totalCost;
    }
}