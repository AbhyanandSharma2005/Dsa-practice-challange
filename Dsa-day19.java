import java.util.Arrays;
import java.util.List;

class Solution {
    public int numOfUnplacedFruits(int[] fruits, int[] baskets) {
        int n = fruits.length;
        boolean[] usedBaskets = new boolean[n];
        int unplacedFruitsCount = 0;
        
        for (int i = 0; i < n; i++) {
            int fruitSize = fruits[i];
            boolean placed = false;
            for (int j = 0; j < n; j++) {
                if (!usedBaskets[j] && baskets[j] >= fruitSize) {
                    usedBaskets[j] = true;
                    placed = true;
                    break;
                }
            }
            
            if (!placed) {
                unplacedFruitsCount++;
            }
        }
        
        return unplacedFruitsCount;
    }
}