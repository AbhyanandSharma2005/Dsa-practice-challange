class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n_str = strs.size();
        int cnt = 0;
        
        int str_length = strs[0].size();
        vector<bool> sorted(n_str - 1, false);
        int j = 0;
        while(j < str_length) {
            vector<bool> current_sorted(n_str - 1, false);
            bool to_delete = false;
            for (int i = 1; i < n_str; i++) {
                if (strs[i - 1][j] > strs[i][j]) {
                    if (sorted[i] == false) {
                        to_delete = true;
                        cnt++;
                        break;
                    }
                } else if (strs[i - 1][j] < strs[i][j]) {
                    current_sorted[i] = true;
                }
            }
            if (to_delete == false) {
                bool all_sorted = true;
                for (int i = 1; i < n_str; i++) {
                    if (sorted[i] == false) {
                        sorted[i] = current_sorted[i];
                        all_sorted = false;
                    }
                }
                if (all_sorted) {
                    return cnt;
                }
            }
            j++;
        }

        return cnt;

    }
};