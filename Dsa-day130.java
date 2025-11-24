class Solution {
    public List<Boolean> prefixesDivBy5(int[] nums) {
        List<Boolean> ans = new ArrayList<>();
        int cur = 0;
        for (int x : nums) {
            cur = (cur * 2 + x) % 5;
            ans.add(cur == 0);
        }
        return ans;
    }
}