class Solution {
    private Map<String, List<Character>> map = new HashMap<>();
    private Set<String> memo = new HashSet<>();

    public boolean pyramidTransition(String bottom, List<String> allowed) {
        for (String s : allowed) {
            String key = s.substring(0, 2);
            map.computeIfAbsent(key, k -> new ArrayList<>()).add(s.charAt(2));
        }
        return dfs(bottom);
    }

    private boolean dfs(String row) {
        if (row.length() == 1) return true;
        if (memo.contains(row)) return false;

        List<String> nextRows = new ArrayList<>();
        buildNextRows(row, 0, new StringBuilder(), nextRows);

        for (String next : nextRows) {
            if (dfs(next)) return true;
        }

        memo.add(row);
        return false;
    }

    private void buildNextRows(String row, int idx, StringBuilder sb, List<String> res) {
        if (idx == row.length() - 1) {
            res.add(sb.toString());
            return;
        }

        String key = row.substring(idx, idx + 2);
        List<Character> options = map.get(key);
        if (options == null) return;

        for (char c : options) {
            sb.append(c);
            buildNextRows(row, idx + 1, sb, res);
            sb.deleteCharAt(sb.length() - 1);
        }
    }
}