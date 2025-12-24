class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int total = 0;
        for (int a : apple) {
            total += a;
        }
        sort(capacity.rbegin(), capacity.rend());
        int sum = 0;
        for (int i = 0; i < capacity.size(); i++) {
            sum += capacity[i];
            if (sum >= total) {
                return i + 1;
            }
        }
        return capacity.size();
    }
};