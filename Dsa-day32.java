public class Solution {
    public boolean judgePoint24(int[] cards) {
        double[] nums = new double[cards.length];
        for (int i = 0; i < cards.length; i++) {
            nums[i] = (double) cards[i];
        }
        return solve(nums);
    }

    private boolean solve(double[] nums) {
        if (nums.length == 1) {
            return Math.abs(nums[0] - 24) < 1e-6;
        }

        for (int i = 0; i < nums.length; i++) {
            for (int j = i + 1; j < nums.length; j++) {
                double[] nextNums = new double[nums.length - 1];
                int index = 0;
                for (int k = 0; k < nums.length; k++) {
                    if (k != i && k != j) {
                        nextNums[index++] = nums[k];
                    }
                }

                double[] results = computeResults(nums[i], nums[j]);
                for (double val : results) {
                    nextNums[index] = val;
                    if (solve(nextNums)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }

    private double[] computeResults(double a, double b) {
        return new double[]{
                a + b,
                a - b,
                b - a,
                a * b,
                Math.abs(b) > 1e-6 ? a / b : Double.NaN,
                Math.abs(a) > 1e-6 ? b / a : Double.NaN
        };
    }
}
