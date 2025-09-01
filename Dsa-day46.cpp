#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        auto gain = [](double p, double t) { return (p + 1) / (t + 1) - p / t; };
        priority_queue<array<double,3>> pq;
        for (auto &c : classes) pq.push({gain(c[0], c[1]), (double)c[0], (double)c[1]});
        while (extraStudents--) {
            auto cur = pq.top(); pq.pop();
            double p = cur[1] + 1, t = cur[2] + 1;
            pq.push({gain(p, t), p, t});
        }
        double sum = 0;
        while (!pq.empty()) {
            auto cur = pq.top(); pq.pop();
            sum += cur[1] / cur[2];
        }
        return sum / classes.size();
    }
};
