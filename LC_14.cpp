#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        if (strs.empty()) return "";   // safety check

        string ans = "";
        int length = strs.size();
        int n = strs[0].size();        // length of first string

        for (int i = 0; i < n; i++) {

            char ch = strs[0][i];
            bool ok = true;

            for (int j = 1; j < length; j++) {

                // IMPORTANT: prevent out-of-range access
                if (i >= strs[j].size() || strs[j][i] != ch) {
                    ok = false;
                    break;
                }
            }

            if (ok)
                ans += ch;
            else
                break;
        }

        return ans;
    }
};

int main() {
    Solution sol;
    vector<string> v = {"flower", "flow", "flight"};
    cout << sol.longestCommonPrefix(v);  // Output: fl
}
