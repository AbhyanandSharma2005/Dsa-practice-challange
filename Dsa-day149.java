class Solution {
    public List<String> validateCoupons(String[] code, String[] businessLine, boolean[] isActive) {
        Map<String, Integer> order = Map.of(
            "electronics", 0,
            "grocery", 1,
            "pharmacy", 2,
            "restaurant", 3
        );
        List<int[]> candidates = new ArrayList<>();
        int n = code.length;
        for (int i = 0; i < n; ++i) {
            String c = code[i];
            String bl = businessLine[i];
            if (!c.isEmpty() && isActive[i] && order.containsKey(bl)) {
                boolean validCode = true;
                for (char ch : c.toCharArray()) {
                    if (!Character.isLetterOrDigit(ch) && ch != '_') {
                        validCode = false;
                        break;
                    }
                }
                if (validCode) {
                    candidates.add(new int[]{order.get(bl), i});
                }
            }
        }
        candidates.sort((a, b) -> {
            if (a[0] != b[0]) return Integer.compare(a[0], b[0]);
            return code[a[1]].compareTo(code[b[1]]);
        });
        List<String> result = new ArrayList<>();
        for (int[] p : candidates) {
            result.add(code[p[1]]);
        }
        return result;
    }
}