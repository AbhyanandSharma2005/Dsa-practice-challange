class Solution {
    public int minimumPushes(String word) {
        int[] freq = new int[26];

        for(char c : word.toCharArray()) {
            freq[c - 'a']++;
        }

        Arrays.sort(freq);

        int[] numbers = new int[8];
        int answer = 0;
        int idx = 0;

        for(int i = 25; i >= 0; i--) {
            if(freq[i] > 0) {
                numbers[idx % 8]++;
                answer += numbers[idx % 8] * freq[i]; 
                idx += 1;
            }
        }

        return answer;
    }
}