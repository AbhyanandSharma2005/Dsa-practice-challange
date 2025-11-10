class Solution {
    public int minOperations(int[] nums) {
        int output = 0;
        Deque<Integer> stack = new ArrayDeque<>();
        for (int num : nums) {
            while (!stack.isEmpty() && stack.peekLast() > num) {
                output++;
                stack.pollLast();
            }
            if (num != 0 && (stack.isEmpty() || stack.peekLast() != num))
                stack.addLast(num);
        }
        return output + stack.size();
    }
}
