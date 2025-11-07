#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> onesRow(m, 0), onesCol(n, 0);
        vector<int> zerosRow(m, 0), zerosCol(n, 0);

        // Count ones and zeros in each row and column
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    onesRow[i]++;
                    onesCol[j]++;
                } else {
                    zerosRow[i]++;
                    zerosCol[j]++;
                }
            }
        }

        // Build the result matrix
        vector<vector<int>> ans(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans[i][j] = onesRow[i] + onesCol[j] - zerosRow[i] - zerosCol[j];
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> grid = {
        {0, 1, 1},
        {1, 0, 1},
        {0, 0, 1}
    };

    vector<vector<int>> result = sol.onesMinusZeros(grid);

    cout << "Result Matrix:\n";
    for (auto &row : result) {
        for (int val : row)
            cout << val << " ";
        cout << endl;
    }

    return 0;
}
