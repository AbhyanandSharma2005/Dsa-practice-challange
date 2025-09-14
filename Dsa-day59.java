class Solution {
    public String[] spellchecker(String[] wordlist, String[] queries) {
        Set<String> exact = new HashSet<>();
        Map<String,String> cap = new HashMap<>();
        Map<String,String> vow = new HashMap<>();
        for (String w : wordlist) exact.add(w);
        for (String w : wordlist) {
            String lw = w.toLowerCase();
            cap.putIfAbsent(lw, w);
            vow.putIfAbsent(devowel(lw), w);
        }
        String[] res = new String[queries.length];
        for (int i=0;i<queries.length;i++) {
            String q = queries[i];
            if (exact.contains(q)) {res[i]=q; continue;}
            String lq = q.toLowerCase();
            if (cap.containsKey(lq)) {res[i]=cap.get(lq); continue;}
            String vq = devowel(lq);
            res[i] = vow.getOrDefault(vq, "");
        }
        return res;
    }
    private String devowel(String s) {
        StringBuilder sb = new StringBuilder();
        for (char c : s.toCharArray()) {
            if ("aeiou".indexOf(c)>=0) sb.append('*');
            else sb.append(c);
        }
        return sb.toString();
    }
}
