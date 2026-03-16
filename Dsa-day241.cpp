class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        set<int> ansSum;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ansSum.insert(grid[i][j]);

                for (int l = 2;; l++) 
                {
                    int lex = j - l + 1;
                    int ley = i + l - 1;
                    int rex = j + l - 1;
                    int rey = i + l - 1;
                    int bex = j;
                    int bey = i + 2 * l - 2;

                    if (lex >= 0 && lex <= n - 1 && ley >= 0 && ley <= m - 1 &&
                        rex >= 0 && rex <= n - 1 && rey >= 0 && rey <= m - 1 &&
                        bex >= 0 && bex <= n - 1 && bey >= 0 && bey <= m - 1) {
                        int sum = 0;
                        for (int a = i, b = j; a <= ley && b >= lex; a++, b--)
                            { sum += grid[a][b]; /*cout << "a " << a << " b " << b << endl; */}
                        for (int a = i, b = j; a <= rey && b <= rex; a++, b++)
                            { sum += grid[a][b]; /* cout << "a " << a << " b " << b << endl; */}
                        for (int a = ley, b = lex; a <= bey && b <= bex; a++, b++)
                            { sum += grid[a][b]; /* cout << "a " << a << " b " << b << endl; */}
                        for (int a = rey, b = rex; a <= bey && b >= bex; a++, b--)
                            { sum += grid[a][b]; /* cout << "a " << a << " b " << b << endl; */}

                        sum -= (grid[i][j] + grid[ley][lex] + grid[rey][rex] +
                                grid[bey][bex]);
                        /*
                        cout << "grid[i][j] " << i << " " << j << grid[i][j] <<endl
                             << "grid[ley][lex] " << ley << " " << lex << grid[ley][lex] << endl
                             << "grid[rey][rex] " << rey << " " << rex << grid[rey][rex] << endl
                             << "grid[bey][bex] " << bey << " " << bex << grid[bey][bex] << endl
                             << "sum " << sum << endl;
                            */
                        ansSum.insert(sum);

                    } else {
                        break;
                    }
                }
            }
        }

        vector<int> ans(ansSum.rbegin(), ansSum.rend());
        if (ans.size() > 3)
            ans.resize(3);

        return ans;
    }
};