import java.util.*;

class Solution {
    public int nextBeautifulNumber(int n) {
        Set<Integer> set = new HashSet<>();
        for (int mask = 1; mask < (1 << 9); mask++) {
            List<Character> digits = new ArrayList<>();
            int total = 0;
            for (int i = 0; i < 9; i++) {
                if ((mask & (1 << i)) != 0) {
                    int d = i + 1;
                    total += d;
                    for (int j = 0; j < d; j++) digits.add((char) ('0' + d));
                }
            }
            if (total == 0 || total > 7) continue;
            permute(set, digits, 0);
        }
        List<Integer> list = new ArrayList<>(set);
        Collections.sort(list);
        for (int x : list) if (x > n) return x;
        return -1;
    }

    void permute(Set<Integer> set, List<Character> arr, int idx) {
        if (idx == arr.size()) {
            if (arr.get(0) != '0') {
                StringBuilder sb = new StringBuilder();
                for (char c : arr) sb.append(c);
                set.add(Integer.parseInt(sb.toString()));
            }
            return;
        }
        for (int i = idx; i < arr.size(); i++) {
            Collections.swap(arr, i, idx);
            permute(set, arr, idx + 1);
            Collections.swap(arr, i, idx);
        }
    }
}
