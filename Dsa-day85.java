class Solution {
    public int maximumEnergy(int[] energy, int k) {
        int n = energy.length;
        for (int i = n - k - 1; i >= 0; i--)
            energy[i] += energy[i + k];
        int ans = energy[0];
        for (int val : energy) ans = Math.max(ans, val);
        return ans;
    }
}
