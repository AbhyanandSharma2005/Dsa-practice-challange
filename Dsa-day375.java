    int[] freq = new int[26];

    int left = 0;
    int ans = 0;

    for (int right = 0; right < s.length(); right++) {

        int current = s.charAt(right) - 'a';

        freq[current]++;

        while (freq[current] > 2) {

            int remove = s.charAt(left) - 'a';

            freq[remove]--;

            left++;
        }

        ans = Math.max(ans, right - left + 1);
    }

    return ans;
}