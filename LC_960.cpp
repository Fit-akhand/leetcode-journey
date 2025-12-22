#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int m = strs.size();
        int n = strs[0].size();

        vector<int> dp(n, 1);
        int best = 1;

        for (int j = 0; j < n; j++) {
            for (int i = 0; i < j; i++) {
                bool valid = true;
                for (int r = 0; r < m; r++) {
                    if (strs[r][i] > strs[r][j]) {
                        valid = false;
                        break;
                    }
                }
                if (valid) {
                    dp[j] = max(dp[j], dp[i] + 1);
                }
            }
            best = max(best, dp[j]);
        }

        return n - best;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m;
    cin >> m;                  // number of strings
    vector<string> strs(m);
    for (int i = 0; i < m; i++) {
        cin >> strs[i];
    }

    Solution sol;
    cout << sol.minDeletionSize(strs) << "\n";

    return 0;
}
