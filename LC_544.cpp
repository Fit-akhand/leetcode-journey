#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].size();
        int deletions = 0;

        for (int col = 0; col < m; col++) {
            for (int row = 1; row < n; row++) {
                if (strs[row][col] < strs[row - 1][col]) {
                    deletions++;
                    break;
                }
            }
        }
        return deletions;
    }
};

int main() {
    Solution sol;
    vector<string> strs = {"abc", "bce", "cae"};
    cout << sol.minDeletionSize(strs) << endl; // Output: 1
    return 0;
}
