#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int i = 0, j = 0, count = 0;

        while (i < g.size() && j < s.size()) {
            if (s[j] >= g[i]) {
                count++;
                i++;
                j++;
            } else {
                j++;
            }
        }
        return count;
    }
};

int main() {
    Solution sol;

    vector<int> g = {1, 2, 3};
    vector<int> s = {1, 1};

    cout << sol.findContentChildren(g, s) << endl;

    return 0;
}
