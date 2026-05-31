class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());

        long long m = (long long)mass;
        for (int &N : asteroids) {
            if (m < (long long)N) return false;
            m += (long long)N;
        }

        return true;
    }
};