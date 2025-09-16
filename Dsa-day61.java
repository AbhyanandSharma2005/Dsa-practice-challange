import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<Integer> replaceNonCoprimes(int[] nums) {
        List<Integer> result = new ArrayList<>();
        for (int num : nums) {
            while (!result.isEmpty() && gcd(num, result.get(result.size() - 1)) > 1) {
                int lastNum = result.remove(result.size() - 1);
                num = (int) ((long) num * lastNum / gcd(num, lastNum));
            }
            result.add(num);
        }
        return result;
    }

    private int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
}