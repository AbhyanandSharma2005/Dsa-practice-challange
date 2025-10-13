class Solution {
    private String getSorted(String s) {
        char[] chars = s.toCharArray();
        Arrays.sort(chars);
        return new String(chars);
    }
    
    public List<String> removeAnagrams(String[] words) {
        List<String> result = new ArrayList<>();
        String prev_sorted_word = "";
        
        for (String word : words) {
            String current_sorted_word = getSorted(word);
            
            if (!current_sorted_word.equals(prev_sorted_word)) {
                result.add(word);
                prev_sorted_word = current_sorted_word;
            }
        }
        
        return result;
    }
}