class Solution {
public:
    int minOperations(vector<int>& nums) {
        int output = 0;
        vector<int> stack;
        for (int num : nums) {
            while (!stack.empty() && stack.back() > num) {
                output++;
                stack.pop_back();
            }
            if (num && (stack.empty() || stack.back() != num))
                stack.push_back(num);
        }
        return output + stack.size();
    }
};
