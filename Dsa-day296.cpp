class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return (a[0] - a[1]) < (b[0] - b[1]);
             });

        int total_effort = 0;
        int current_energy = 0;

        for (auto& task : tasks) {
            if (current_energy < task[1]) {
                total_effort += (task[1] - current_energy);
                current_energy = task[1];
            }
            current_energy -= task[0];
        }

        return total_effort;
    }
};