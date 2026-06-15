class Solution {
public:
    int pairSum(ListNode* head) {
        vector<int> vals;

        while (head) {
            vals.push_back(head->val);
            head = head->next;
        }

        int n = vals.size();
        int ans = 0;

        for (int i = 0; i < n / 2; i++) {
            ans = max(ans, vals[i] + vals[n - 1 - i]);
        }

        return ans;
    }
};