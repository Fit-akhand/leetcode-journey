#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // 🔹 Recursion (for understanding)
    int solveUsingRecursion(vector<int>& coins, int amount) {
        if (amount == 0) return 0;

        int mini = INT_MAX;

        for (int coin : coins) {
            if (coin <= amount) {
                int ans = solveUsingRecursion(coins, amount - coin);
                if (ans != INT_MAX) {
                    mini = min(mini, 1 + ans);
                }
            }
        }
        return mini;
    }

    // 🔹 Memoization (Top-Down DP)
    int solveUsingDp(vector<int>& coins, int amount, vector<int>& dp) {
        if (amount == 0) return 0;

        if (dp[amount] != -1) return dp[amount];

        int mini = INT_MAX;

        for (int coin : coins) {
            if (coin <= amount) {
                int ans = solveUsingDp(coins, amount - coin, dp);
                if (ans != INT_MAX) {
                    mini = min(mini, 1 + ans);
                }
            }
        }

        return dp[amount] = mini;
    }

    // 🔹 Tabulation (Bottom-Up DP)
    int solveUsingTab(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX);

        dp[0] = 0; // base case

        for (int value = 1; value <= amount; value++) {
            for (int coin : coins) {
                if (coin <= value && dp[value - coin] != INT_MAX) {
                    dp[value] = min(dp[value], 1 + dp[value - coin]);
                }
            }
        }

        return dp[amount];
    }

    int coinChange(vector<int>& coins, int amount) {
        int ans = solveUsingTab(coins, amount);
        return (ans == INT_MAX) ? -1 : ans;
    }
};

int main() {
    Solution obj;

    vector<int> coins = {1, 2, 5};
    int amount = 11;

    int result = obj.coinChange(coins, amount);

    if (result == -1) {
        cout << "Not possible to form amount\n";
    } else {
        cout << "Minimum coins required: " << result << endl;
    }

    return 0;
}