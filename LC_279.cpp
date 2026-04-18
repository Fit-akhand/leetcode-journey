#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int solveUsingMem(int n, vector<int> &dp){
        // base cases
        if(n == 0) return 0;
        if(n < 0) return INT_MAX;

        if(dp[n] != -1) return dp[n];

        int ans = INT_MAX;

        for(int i = 1; i*i <= n; i++){
            int res = solveUsingMem(n - i*i, dp);

            if(res != INT_MAX){
                ans = min(ans, 1 + res);
            }
        }

        return dp[n] = ans;
    }

    int numSquares(int n) {
        vector<int> dp(n + 1, -1);
        return solveUsingMem(n, dp);
    }
};

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    Solution obj;
    cout << "Minimum number of perfect squares: "
         << obj.numSquares(n) << endl;

    return 0;
}