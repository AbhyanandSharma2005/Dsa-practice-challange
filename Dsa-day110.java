import java.util.*;
class Solution {
    public int[] findXSum(int[] nums, int k, int x) {
        int n = nums.length;
        int[] res = new int[n - k + 1];
        for (int i = 0; i <= n - k; i++) {
            int[] sub = Arrays.copyOfRange(nums, i, i + k);
            Map<Integer, Integer> freq = new HashMap<>();
            for (int num : sub) freq.put(num, freq.getOrDefault(num, 0) + 1);
            List<int[]> list = new ArrayList<>();
            for (Map.Entry<Integer, Integer> e : freq.entrySet()) 
                list.add(new int[]{e.getKey(), e.getValue()});
            list.sort((a, b) -> b[1] == a[1] ? b[0] - a[0] : b[1] - a[1]);
            Set<Integer> keep = new HashSet<>();
            for (int j = 0; j < Math.min(x, list.size()); j++) keep.add(list.get(j)[0]);
            int sum = 0;
            for (int num : sub) if (keep.contains(num)) sum += num;
            res[i] = sum;
        }
        return res;
    }
}
