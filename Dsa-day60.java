class Solution {
    public int canBeTypedWords(String text, String brokenLetters) {
        Set<Character> broken = new HashSet<>();
        for (char c : brokenLetters.toCharArray()) broken.add(c);
        int count = 0;
        for (String word : text.split(" ")) {
            boolean ok = true;
            for (char c : word.toCharArray()) {
                if (broken.contains(c)) {
                    ok = false;
                    break;
                }
            }
            if (ok) count++;
        }
        return count;
    }
}
