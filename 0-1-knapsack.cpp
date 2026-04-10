#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // 🔹 1. Recursion
    int solveByRec(int W, vector<int> &val, vector<int> &wt, int index){
        if(index >= val.size()) return 0;

        int include = 0;
        if(W >= wt[index]){
            include = val[index] + solveByRec(W - wt[index], val, wt, index + 1);
        }

        int exclude = solveByRec(W, val, wt, index + 1);

        return max(include, exclude);
    }

    // 🔹 2. Memoization
    int solveByMem(int W, vector<int> &val, vector<int> &wt, int index, vector<vector<int>>& dp){
        if(index >= val.size()) return 0;

        if(dp[W][index] != -1) return dp[W][index];

        int include = 0;
        if(W >= wt[index]){
            include = val[index] + solveByMem(W - wt[index], val, wt, index + 1, dp);
        }

        int exclude = solveByMem(W, val, wt, index + 1, dp);

        return dp[W][index] = max(include, exclude);
    }

    // 🔹 3. Tabulation
    int SolveByTabulation(int W, vector<int> &val, vector<int> &wt){
        int n = wt.size();
        vector<vector<int>> dp(W + 1, vector<int>(n + 1, 0));

        for(int i = n - 1; i >= 0; i--){
            for(int c = 0; c <= W; c++){
                int include = 0;
                if(c >= wt[i]){
                    include = val[i] + dp[c - wt[i]][i + 1];
                }
                int exclude = dp[c][i + 1];

                dp[c][i] = max(include, exclude);
            }
        }

        return dp[W][0];
    }

    // 🔹 4. Space Optimization (2 arrays)
    int SolveForSpaceOpti(int W, vector<int> &val, vector<int> &wt){
        int n = wt.size();
        vector<int> curr(W + 1, 0);
        vector<int> next(W + 1, 0);

        for(int i = n - 1; i >= 0; i--){
            for(int c = 0; c <= W; c++){
                int include = 0;
                if(c >= wt[i]){
                    include = val[i] + next[c - wt[i]];
                }
                int exclude = next[c];

                curr[c] = max(include, exclude);
            }
            next = curr;
        }

        return next[W];
    }

    // 🔹 5. Space Optimization (1 array) ⭐ BEST
    int SolveForSpaceOpti2(int W, vector<int> &val, vector<int> &wt){
        int n = wt.size();
        vector<int> dp(W + 1, 0);

        for(int i = n - 1; i >= 0; i--){
            for(int c = W; c >= 0; c--){
                int include = 0;
                if(c >= wt[i]){
                    include = val[i] + dp[c - wt[i]];
                }
                int exclude = dp[c];

                dp[c] = max(include, exclude);
            }
        }

        return dp[W];
    }

    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // Choose any method:

        // return solveByRec(W, val, wt, 0);

        // vector<vector<int>> dp(W+1, vector<int>(val.size()+1, -1));
        // return solveByMem(W, val, wt, 0, dp);

        // return SolveByTabulation(W, val, wt);

        // return SolveForSpaceOpti(W, val, wt);

        return SolveForSpaceOpti2(W, val, wt); // ⭐ recommended
    }
};

int main() {
    Solution obj;

    int n;
    cout << "Enter number of items: ";
    cin >> n;

    vector<int> val(n), wt(n);

    cout << "Enter values:\n";
    for(int i = 0; i < n; i++) cin >> val[i];

    cout << "Enter weights:\n";
    for(int i = 0; i < n; i++) cin >> wt[i];

    int W;
    cout << "Enter knapsack capacity: ";
    cin >> W;

    int result = obj.knapsack(W, val, wt);

    cout << "Maximum value: " << result << endl;

    return 0;
}