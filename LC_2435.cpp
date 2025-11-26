#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        const int MOD = 1000000007;

        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k, 0)));

        dp[0][0][grid[0][0] % k] = 1;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                for(int r = 0; r < k; r++) {

                    if(i > 0) {
                        int newR = (r + grid[i][j]) % k;
                        dp[i][j][newR] = (dp[i][j][newR] + dp[i-1][j][r]) % MOD;
                    }

                    if(j > 0) {
                        int newR = (r + grid[i][j]) % k;
                        dp[i][j][newR] = (dp[i][j][newR] + dp[i][j-1][r]) % MOD;
                    }
                }
            }
        }

        return dp[m-1][n-1][0];
    }
};

int main() {
    int m, n, k;
    cin >> m >> n >> k;

    vector<vector<int>> grid(m, vector<int>(n));

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    Solution obj;
    cout << obj.numberOfPaths(grid, k) << endl;

    return 0;
}
