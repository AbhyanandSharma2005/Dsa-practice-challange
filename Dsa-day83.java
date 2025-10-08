import java.util.Arrays;

class Solution {
    public int[] successfulPairs(int[] spells, int[] potions, long success) {
        Arrays.sort(potions);
        
        int n = spells.length;
        int m = potions.length;
        int[] pairs = new int[n];

        for (int i = 0; i < n; ++i) {
            long spell_strength = spells[i];
            
            long required_potion_strength = (success + spell_strength - 1) / spell_strength;
            
            int low = 0;
            int high = m;
            int k = m; 

            while (low < high) {
                int mid = low + (high - low) / 2;
                if (potions[mid] < required_potion_strength) {
                    low = mid + 1;
                } else {
                    k = mid;
                    high = mid;
                }
            }
            
            pairs[i] = m - k;
        }
        
        return pairs;
    }
}