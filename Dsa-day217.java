class Solution {
    public String makeLargestSpecial(String s) {
        int count = 0, start = 0;
        List<String> specials = new ArrayList<>();
        for (int i = 0; i < s.length(); i++) {
            count += s.charAt(i) == '1' ? 1 : -1;
            if (count == 0) {
                specials.add("1" + makeLargestSpecial(s.substring(start + 1, i)) + "0");
                start = i + 1;
            }
        }
        specials.sort(Collections.reverseOrder());
        return String.join("", specials);
    }
}