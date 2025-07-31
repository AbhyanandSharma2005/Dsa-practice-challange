import java.util.*;

class Solution {
    public int subarrayBitwiseORs(int[] arr) {
        Set<Integer> res = new HashSet<>();
        Set<Integer> prev = new HashSet<>();

        for (int num : arr) {
            Set<Integer> cur = new HashSet<>();
            cur.add(num);
            for (int val : prev) {
                cur.add(val | num);
            }
            res.addAll(cur);
            prev = cur;
        }

        return res.size();
    }
}
