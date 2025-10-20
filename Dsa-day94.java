class Solution {
    public String findLexSmallestString(String s, int a, int b) {
        Queue<String> q = new LinkedList<>();
        Set<String> seen = new HashSet<>();
        q.add(s);
        String ans = s;
        while (!q.isEmpty()) {
            String curr = q.poll();
            if (seen.contains(curr)) continue;
            seen.add(curr);
            if (curr.compareTo(ans) < 0) ans = curr;
            char[] arr = curr.toCharArray();
            for (int i = 1; i < arr.length; i += 2)
                arr[i] = (char) ((arr[i] - '0' + a) % 10 + '0');
            String added = new String(arr);
            String rotated = curr.substring(curr.length() - b) + curr.substring(0, curr.length() - b);
            if (!seen.contains(added)) q.add(added);
            if (!seen.contains(rotated)) q.add(rotated);
        }
        return ans;
    }
}
