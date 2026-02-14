#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> dp(query_row + 2, vector<double>(query_row + 2, 0.0));
        
        dp[0][0] = poured;
        
        for (int r = 0; r <= query_row; ++r) {
            for (int c = 0; c <= r; ++c) {
                if (dp[r][c] > 1.0) {
                    double overflow = (dp[r][c] - 1.0) / 2.0;
                    dp[r+1][c] += overflow;
                    dp[r+1][c+1] += overflow;
                }
            }
        }
        
        return min(1.0, dp[query_row][query_glass]);
    }
};

int main() {
    Solution sol;

    int poured, row, glass;
    cout << "Enter poured, query_row, query_glass: ";
    cin >> poured >> row >> glass;

    double result = sol.champagneTower(poured, row, glass);

    cout << "Amount in glass: " << result << endl;

    return 0;
}
